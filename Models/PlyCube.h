static const Vtx PlyCube_vtx0[]= {
   {-50,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,-50,  0,  0<< 6,1<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,150,  0,  0<< 6,1<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,-50,  0,  0<< 6,1<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},

};
static const Vtx PlyCube_vtx1[]= {
   {150,-50,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,-50,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {-50,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,150,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},
   {150,150,-50,  0,  0<< 6,0<< 6,  0xFF,0xFF,0xFF,0xFF},

};




static const Gfx PlyCube_dl[] = {
   gsDPSetCycleType(G_CYC_2CYCLE),
   gsSPTexture(0, 0, 0, 0, G_OFF),
   gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
   gsSPSetGeometryMode(G_SHADE | G_CLIPPING | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BACK | G_ZBUFFER),
   
gsSPVertex(PlyCube_vtx0,33,0),

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
gsSPVertex(PlyCube_vtx1,33,0),

    gsSP1Triangle(0,1,2, 0),
   gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void PlyCube_mesh();
void PlyCube_mesh(){
    current_mesh.size = 24;
    current_mesh.vertices = PlyCube_vtx0;
    current_mesh.settings = PlyCube_dl;
};