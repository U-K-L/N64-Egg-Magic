#ifndef N64_GRAPHIC_H
#define N64_GRAPHIC_H

#define SP 100 //Scale of the entire rendering engine, no floating point so 100 default value.


typedef struct 
{
    Vtx const *vertices;
    int size;
    Gfx const *settings;
}Mesh;
extern Mesh current_mesh;
extern Mesh current_mesh2;



// _MESHES_
static const Vtx triangle_vtx[] = {
  //x,y,z (position), flag (used to align memory), u,v (texture coords), R,G,B,A (vertex color)
  {-SP/2,-SP/2, -5,  0,  0,0,  0xff,0xff,0xff,0xff},
  {SP/2,-SP/2,  -5,  0,  0,0,  0xff,0xff,0xff,0xff},
  {0,SP/2,    -5,  0,  0,0,  0xff,0xff,0xff,0xff},
};

static const Gfx triangle_dl[] = {
    gsSPVertex(triangle_vtx,8, 0),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE| G_SHADING_SMOOTH),
    gsSP1Triangle(0,1,2,0),
    gsSPEndDisplayList(),
};

void triangle_mesh(Mesh mesh);
void triangle_mesh(Mesh mesh)
{
  mesh.size = 8;
  mesh.vertices = triangle_vtx;
  mesh.settings = triangle_dl;
};


//_END_MESHES_

// Gfx state:
typedef struct {
  Mtx     projection;
  Mtx     modeling;
  Mtx     rotate_z;
  Mtx     rotate_y;
  Mtx     rotate_x;
  Mtx     camera;
} Dynamic;
extern Dynamic gfx_dynamic;

typedef struct view {
	short   view_scale[4]; 
	short   view_transformation[4];
	long long int   force_structure_alignment;
};

//Example meshes for debugging:
static const Vtx shade_vtx[] =  {
    // -X face, bright red.
    {{{-SP, -SP, -SP}, 0, {0, 0}, {255, 128, 128, 255}}},
    {{{-SP, -SP, +SP}, 0, {0, 0}, {255, 128, 128, 255}}},
    {{{-SP, +SP, -SP}, 0, {0, 0}, {255, 128, 128, 255}}},
    {{{-SP, +SP, +SP}, 0, {0, 0}, {255, 128, 128, 255}}},
    // +X face, dark red.
    {{{+SP, -SP, -SP}, 0, {0, 0}, {128, 0, 0, 255}}},
    {{{+SP, -SP, +SP}, 0, {0, 0}, {128, 0, 0, 255}}},
    {{{+SP, +SP, -SP}, 0, {0, 0}, {128, 0, 0, 255}}},
    {{{+SP, +SP, +SP}, 0, {0, 0}, {128, 0, 0, 255}}},
    // -Y face, bright green.
    {{{-SP, -SP, -SP}, 0, {0, 0}, {128, 255, 128, 255}}},
    {{{+SP, -SP, -SP}, 0, {0, 0}, {128, 255, 128, 255}}},
    {{{-SP, -SP, +SP}, 0, {0, 0}, {128, 255, 128, 255}}},
    {{{+SP, -SP, +SP}, 0, {0, 0}, {128, 255, 128, 255}}},
    // +Y face, dark green.
    {{{-SP, +SP, -SP}, 0, {0, 0}, {0, 128, 0, 255}}},
    {{{+SP, +SP, -SP}, 0, {0, 0}, {0, 128, 0, 255}}},
    {{{-SP, +SP, +SP}, 0, {0, 0}, {0, 128, 0, 255}}},
    {{{+SP, +SP, +SP}, 0, {0, 0}, {0, 128, 0, 255}}},
    // -Z face, bright blue.
    {{{-SP, -SP, -SP}, 0, {0, 0}, {128, 128, 255, 255}}},
    {{{-SP, +SP, -SP}, 0, {0, 0}, {128, 128, 255, 255}}},
    {{{+SP, -SP, -SP}, 0, {0, 0}, {128, 128, 255, 255}}},
    {{{+SP, +SP, -SP}, 0, {0, 0}, {128, 128, 255, 255}}},
    // +Z face, dark blue.
    {{{-SP, -SP, +SP}, 0, {0, 0}, {0, 0, 128, 255}}},
    {{{-SP, +SP, +SP}, 0, {0, 0}, {0, 0, 128, 255}}},
    {{{+SP, -SP, +SP}, 0, {0, 0}, {0, 0, 128, 255}}},
    {{{+SP, +SP, +SP}, 0, {0, 0}, {0, 0, 128, 255}}},
};
static const Gfx shade_dl[] = {
      gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPSetGeometryMode(G_SHADE | G_CLIPPING | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BACK | G_ZBUFFER),
    gsSPVertex(shade_vtx,24, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(12, 14, 13, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(20, 22, 21, 0, 21, 22, 23, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void shade_mesh(Mesh *mesh);
void shade_mesh(Mesh *mesh)
{
  mesh->size = 24;
  mesh->vertices = shade_vtx;
  mesh->settings = shade_dl;
};

static const Vtx AShapeColor_vtx[] = {
   {-78,-16,99,  0,  0,0,  30,255,49,255},
   {53,118,123,  0,  0,0,  255,149,211,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {-5,-77,-40,  0,  0,1,  39,233,255,255},
   {52,-1,-69,  0,  0,0,  35,233,255,255},
   {26,-78,56,  0,  0,0,  35,233,255,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {-5,-77,-40,  0,  0,0,  39,233,255,255},
   {-17,73,-81,  0,  0,0,  102,236,255,255},
   {-5,-77,-40,  0,  0,0,  39,233,255,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {-17,73,-81,  0,  0,0,  102,236,255,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {52,-1,-69,  0,  0,0,  35,233,255,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {-82,123,-78,  0,  0,0,  33,237,235,255},
   {-17,73,-81,  0,  0,0,  102,236,255,255},
   {-143,33,102,  0,  0,0,  113,255,119,255},
   {-82,123,-78,  0,  0,0,  33,237,235,255},
   {-162,15,-37,  0,  0,0,  35,233,255,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {-143,33,102,  0,  0,0,  113,255,119,255},
   {-78,-16,99,  0,  0,0,  30,255,49,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {-82,123,-78,  0,  0,0,  33,237,235,255},
   {-45,164,53,  0,  0,0,  19,255,45,255},
   {-78,-16,99,  0,  0,0,  30,255,49,255},
   {-162,15,-37,  0,  0,0,  35,233,255,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {-45,-13,173,  0,  0,0,  19,255,43,255},
   {128,19,95,  0,  0,0,  90,147,255,255},
   {53,118,123,  0,  0,0,  255,149,211,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {104,-148,25,  0,  0,1,  45,234,255,255},
   {26,-78,56,  0,  0,1,  35,233,255,255},
   {26,-78,56,  0,  0,0,  35,233,255,255},
   {-45,-13,173,  0,  0,0,  19,255,43,255},
   {-78,-16,99,  0,  0,0,  30,255,49,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {128,19,95,  0,  0,0,  90,147,255,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {173,-55,-10,  0,  0,0,  108,237,255,255},
   {136,-145,98,  0,  0,1,  90,147,255,255},
   {104,-148,25,  0,  0,1,  45,234,255,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {206,-52,63,  0,  0,0,  255,58,90,255},
   {173,-55,-10,  0,  0,0,  108,237,255,255},
   {58,-74,130,  0,  0,0,  113,159,255,255},
   {206,-52,63,  0,  0,0,  255,58,90,255},
   {26,-78,56,  0,  0,0,  35,233,255,255},
   {136,-145,98,  0,  0,0,  90,147,255,255},
   {58,-74,130,  0,  0,0,  113,159,255,255},
   {-45,-13,173,  0,  0,0,  19,255,43,255},
   {26,-78,56,  0,  0,1,  35,233,255,255},
   {26,-78,56,  0,  0,0,  35,233,255,255},
   {-78,-16,99,  0,  0,0,  30,255,49,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {52,-1,-69,  0,  0,0,  35,233,255,255},
   {-17,73,-81,  0,  0,0,  102,236,255,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {95,15,21,  0,  0,0,  35,233,255,255},
   {-97,-34,-40,  0,  0,0,  79,235,255,255},
   {-162,15,-37,  0,  0,0,  35,233,255,255},
   {-82,123,-78,  0,  0,0,  33,237,235,255},
   {-45,164,53,  0,  0,0,  19,255,45,255},
   {-45,164,53,  0,  0,0,  19,255,45,255},
   {20,114,50,  0,  0,0,  90,147,255,255},
   {-17,73,-81,  0,  0,0,  102,236,255,255},
   {-82,123,-78,  0,  0,0,  33,237,235,255},
   {-143,33,102,  0,  0,0,  113,255,119,255},
   {173,-55,-10,  0,  0,0,  108,237,255,255},
   {58,-74,130,  0,  0,0,  113,159,255,255},
   {53,118,123,  0,  0,0,  255,149,211,255},
   {173,-55,-10,  0,  0,0,  108,237,255,255},
   {206,-52,63,  0,  0,0,  255,58,90,255},
   {136,-145,98,  0,  0,1,  90,147,255,255},
   {128,19,95,  0,  0,0,  90,147,255,255},
   {136,-145,98,  0,  0,0,  90,147,255,255},
   {104,-148,25,  0,  0,0,  45,234,255,255},
}; //size of verts --- 80

static const Gfx AShapeColor_dl[] = {
    gsSPVertex(AShapeColor_vtx,80, 0),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE| G_SHADING_SMOOTH),

    //gsSP1Triangle(-3.635682,2.236320,-1.000000, 0),
    gsSP1Triangle(0,1,2, 0),
    gsSP1Triangle(3,4,5, 0),
    gsSP1Triangle(6,7,8, 0),
    gsSP1Triangle(9,10,11, 0),
    gsSP1Triangle(12,13,14, 0),
    gsSP1Triangle(15,16,17, 0),
    gsSP1Triangle(18,19,20, 0),
    gsSP1Triangle(21,22,23, 0),
    gsSP1Triangle(24,25,26, 0),
    gsSP1Triangle(27,28,29, 0),
    gsSP1Triangle(30,31,32, 0),
    gsSP1Triangle(33,34,35, 0),
    gsSP1Triangle(36,37,38, 0),
    gsSP1Triangle(39,40,41, 0),
    gsSP1Triangle(42,43,44, 0),
    gsSP1Triangle(45,46,47, 0),
    gsSP1Triangle(48,49,31, 0),
    gsSP1Triangle(50,51,52, 0),
    gsSP1Triangle(0,53,1, 0),
    gsSP1Triangle(3,54,4, 0),
    gsSP1Triangle(55,56,57, 0),
    gsSP1Triangle(9,58,10, 0),
    gsSP1Triangle(59,60,61, 0),
    gsSP1Triangle(62,63,64, 0),
    gsSP1Triangle(18,65,19, 0),
    gsSP1Triangle(21,66,22, 0),
    gsSP1Triangle(67,68,69, 0),
    gsSP1Triangle(27,70,28, 0),
    gsSP1Triangle(30,48,31, 0),
    gsSP1Triangle(33,71,34, 0),
    gsSP1Triangle(36,72,37, 0),
    gsSP1Triangle(39,73,40, 0),
    gsSP1Triangle(74,75,76, 0),
    gsSP1Triangle(45,77,46, 0),
    gsSP1Triangle(48,78,49, 0),
    gsSP1Triangle(50,79,51, 0),

    gsSPEndDisplayList(),
};

void test_mesh();
void test_mesh()
{
  current_mesh.size = 80;
  current_mesh.vertices = AShapeColor_vtx;
  current_mesh.settings = AShapeColor_dl;
};




static const Vtx BlenderCube_vtx[] = {
   {-10,10,10,  0,  0,0,  17,27,255,255},
   {10,-10,10,  0,  0,0,  38,44,255,255},
   {10,10,10,  0,  0,0,  9,255,29,255},
   {10,-10,10,  0,  0,0,  38,44,255,255},
   {-10,-10,-10,  0,  0,1,  0,21,255,255},
   {10,-10,-10,  0,  0,0,  179,42,248,255},
   {-10,-10,10,  0,  0,0,  0,21,255,255},
   {-10,10,-10,  0,  0,0,  255,3,239,255},
   {-10,-10,-10,  0,  0,0,  0,21,255,255},
   {10,10,-10,  0,  0,0,  0,255,28,255},
   {-10,-10,-10,  0,  0,0,  0,21,255,255},
   {-10,10,-10,  0,  0,0,  255,3,239,255},
   {10,10,10,  0,  0,0,  9,255,29,255},
   {10,-10,-10,  0,  0,0,  179,42,248,255},
   {10,10,-10,  0,  0,0,  0,255,28,255},
   {-10,10,10,  0,  0,0,  17,27,255,255},
   {10,10,-10,  0,  0,0,  0,255,28,255},
   {-10,10,-10,  0,  0,0,  255,3,239,255},
   {-10,-10,10,  0,  0,0,  0,21,255,255},
   {-10,-10,10,  0,  0,1,  0,21,255,255},
   {-10,10,10,  0,  0,0,  17,27,255,255},
   {10,-10,-10,  0,  0,0,  179,42,248,255},
   {10,-10,10,  0,  0,0,  38,44,255,255},
   {10,10,10,  0,  0,0,  9,255,29,255},
}; //size of verts --- 24

static const Gfx BlenderCube_dl[] = {
    gsSPVertex(BlenderCube_vtx,24, 0),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE| G_SHADING_SMOOTH),

    //gsSP1Triangle(-3.635682,2.236320,-1.000000, 0),
    gsSP1Triangle(0,1,2, 0),
    gsSP1Triangle(3,4,5, 0),
    gsSP1Triangle(6,7,8, 0),
    gsSP1Triangle(9,10,11, 0),
    gsSP1Triangle(12,13,14, 0),
    gsSP1Triangle(15,16,17, 0),
    gsSP1Triangle(0,18,1, 0),
    gsSP1Triangle(3,19,4, 0),
    gsSP1Triangle(6,20,7, 0),
    gsSP1Triangle(9,21,10, 0),
    gsSP1Triangle(12,22,13, 0),
    gsSP1Triangle(15,23,16, 0),

    gsSPEndDisplayList(),
};

void blenderCube_mesh();
void blenderCube_mesh()
{
  current_mesh.size = 24;
  current_mesh.vertices = BlenderCube_vtx;
  current_mesh.settings = BlenderCube_dl;
};

#endif