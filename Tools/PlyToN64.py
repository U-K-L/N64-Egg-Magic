import os
import sys
import math

#Made by U.K.L.
#Usage: python PlyToN64.py <file> <size> <offset>
#Example: python PlyToN64.py PLYFiles/PlyCube.ply 100 50

definitions = []
size = 0
Lines = ""
data_object = {}
scalingFactor = 50
center = 0

verticesList = []
vertexCache = []
indexer = 0

if(len(sys.argv) > 2):
    scalingFactor = int(sys.argv[2])
if(len(sys.argv) > 3):
    center = int(sys.argv[3])
words = sys.argv[1].split("/")

name = words[len(words)-1].replace(".ply", "")



vertices = "static const Vtx " + name+ "_vtx" +str(indexer)+"[]= {\n"
with open(sys.argv[1], 'r') as f:
    Lines = f.readlines()



def getProperties(_aline):
    temp = _aline
    if("element vertex" in temp):
        tokens = temp.split()
        global size 
        size = int(tokens[2])
        
    if("property" in temp):
        definitions.append(temp.replace("\n", ""))

def createString(vertex):
    global scalingFactor
    x =  str(math.floor(float(vertex["property float x"])*scalingFactor+center ))
    y = str(math.floor(float(vertex["property float y"])*scalingFactor+center))
    z = str(math.floor(float(vertex["property float z"])*scalingFactor+center))
    s = "0"
    t = "0"
    if("property float s" in vertex):
        s = str(math.floor(float(vertex["property float s"]))) + "<< 6"
    if("property float t" in vertex):
        t = str(math.floor(float(vertex["property float t"]))) + "<< 6"

    r = "0xFF"
    g = "0xFF"
    b = "0xFF"
    a = "0xFF"
    if("property uchar red" in vertex):
        r = str(hex(math.floor(float(vertex["property uchar red"])) ))
    if("property uchar green" in vertex):
        g = str(hex(math.floor(float(vertex["property uchar green"])) ))
    if("property uchar blue" in vertex):
        b = str(hex(math.floor(float(vertex["property uchar blue"])) ))
    if("property uchar alpha" in vertex):
        a = str(hex(math.floor(float(vertex["property uchar alpha"])) ))
    vert = ("   {"+x+","+y+","+z + ",  " + "0" + ",  " + s + "," + t + ",  " + r + "," + g + "," + b + "," + a + "},\n")
    global vertices
    vertices += vert


def getValues(line):
    global indexer
    global vertices
    totalVertexCount =0
    for vert in vertexCache:
        totalVertexCount += 1
        if(totalVertexCount%32 == 0):
            indexer += 1
            vertices += "\n};"
            vertices += "\nstatic const Vtx " + name+ "_vtx" +str(indexer)+"[]= {\n"
        tokens = vert.split()
        vertex = {}
        for i in range(len(tokens)):
            vertex[definitions[i]] = tokens[i]
        createString(vertex)
    vertices += "\n};"

def getTriangles():
    global vertices
    index = 0
    indexer = 0
    triangleCount = 0
    for i in range(0, len(vertexCache), 3):
        if triangleCount % 11 == 0:
            index = 0
            command = "    gsSP1Triangle(" + str(index) + "," + str(index+1) + "," + str(index+2) + ", 0),"
            vertices += "   " + "\ngsSPVertex(" + name + "_vtx"+str(indexer)+"," + "33" + ","+"0"+"),\n"

            indexer += 1
            triangleCount = 0
        else:
            command = "    gsSP1Triangle(" + str(index) + "," + str(index+1) + "," + str(index+2) + ", 0),"
        index += 3
        vertices += "\n"+command
        triangleCount += 1

for line in Lines:
    getProperties(line)


def buildVertexCache(line, triangleCount):
    tokens = line.split()
    vertexCache.append(verticesList[int(tokens[1])])
    vertexCache.append(verticesList[int(tokens[2])])
    vertexCache.append(verticesList[int(tokens[3])])


#Store all the vertices into the list.
def getVertexList():
    end_of_header = False
    index = 0
    triangleCount = 0
    for line in Lines:
        global size
        if(end_of_header == True and index < size):
            verticesList.append(line)
            index += 1
        elif(index >= size):
            buildVertexCache(line, triangleCount)
            triangleCount += 1
        if("end_header"in line):
            end_of_header = True


getVertexList()

begin = False
index = 0
getValues(line)
for line in Lines:

    if("end_header" in line):
        begin = True
        index = 0
        continue
    if(begin == True):
        index += 1
    if(index >= size):
        if(index == size):
            vertices += "\n\n\n\n\n"
            vertices += "static const Gfx "+ name +"_dl[] = {\n"
            vertices += "   " + "gsDPSetCycleType(G_CYC_2CYCLE),\n"
            vertices += "   " + "gsSPTexture(0, 0, 0, 0, G_OFF),\n"
            vertices += "   " + "gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),\n"
            vertices += "   " + "gsSPSetGeometryMode(G_SHADE | G_CLIPPING | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BACK | G_ZBUFFER),\n"
            #vertices += "   " + "gsSPVertex(" + name + "_vtx," + str(size) + ",0),\n"
            begin = False
            index += 1
            continue
        begin = False
        index += 1
getTriangles()
vertices += "\n   " + "gsDPPipeSync(),"
vertices += "\n    gsSPEndDisplayList(),"
vertices += "\n};\n\n" +"void "+ name + "_mesh();" + "\n" + "void " + name + "_mesh(){"
vertices += "\n    " + "current_mesh.size = " + str(size) +";" 
vertices += "\n    " + "current_mesh.vertices = " + name + "_vtx0" +";" 
vertices += "\n    " + "current_mesh.settings = " + name + "_dl" +";" + "\n};"
print(vertices)

file_name= name.replace(".ply", "")+ ".h"
f = open("../Models/"+file_name, "w")
f.write(vertices)
f.close()