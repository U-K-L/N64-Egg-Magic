static const Vtx PlyCube_vtx[] = {
   {-200,200,200,  0,  0,0,  0x6b,0x2b,0x1b,0xFF},
   {200,200,-200,  0,  0,0,  0x6b,0x2b,0x1b,0xFF},
   {200,200,200,  0,  0,0,  0x6b,0x2b,0x1b,0xFF},
   {200,200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-200,-200,-200,  0,  0,1,  0xFF,0xFF,0xFF,0xFF},
   {200,-200,-200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,200,-200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,-200,200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,-200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,-200,200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,-200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-200,-200,200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,200,200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {200,-200,-200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {200,-200,200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,200,200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,-200,200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-200,-200,200,  0,  0,0,   0x6b,0x2b,0x1b,0xFF},
   {-200,200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-200,200,-200,  0,  0,1,  0xFF,0xFF,0xFF,0xFF},
   {-200,200,200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,-200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,200,-200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {200,200,200,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
}; //size of verts --- 24




static const Gfx PlyCube_dl[] = {
   gsDPPipeSync(),
   gsDPSetCycleType(G_CYC_1CYCLE),
   gsSPTexture(0, 0, 0, 0, G_OFF),
   gsSPSetGeometryMode(G_SHADE | G_CULL_BACK),
   gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
   gsSPVertex(PlyCube_vtx,24,0),

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

void PlyCube_mesh();
void PlyCube_mesh(){
    current_mesh.size = 24;
    current_mesh.vertices = PlyCube_vtx;
    current_mesh.settings = PlyCube_dl;
};