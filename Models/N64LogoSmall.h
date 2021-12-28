static const Vtx N64LogoSmall_vtx[] = {
   {-50,-111,50,  0,  0,-1,  0xFF,0xFF,0xFF,0xFF},
   {-110,-111,110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-110,-111,50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-50,-111,110,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {109,-111,-111,  0,  0,-1,  0xFF,0xFF,0xFF,0xFF},
   {49,-111,-51,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {49,-111,-111,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {109,-111,-51,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {110,110,109,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {50,110,49,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {50,110,109,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {110,110,49,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {109,110,-51,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {49,110,-111,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {49,110,-51,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {109,110,-111,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,110,-50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-111,110,-110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-111,110,-50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,110,-110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-50,110,110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-110,110,50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-110,110,110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-50,110,50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {50,-111,109,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {110,-111,49,  0,  0,-1,  0xFF,0xFF,0xFF,0xFF},
   {110,-111,109,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {50,-111,49,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,-111,-110,  0,  0,-1,  0xFF,0xFF,0xFF,0xFF},
   {-111,-111,-50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-111,-111,-110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,-111,-50,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {-50,0,50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-110,0,50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {49,0,-51,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {109,0,-51,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,0,-50,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {-111,0,-50,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {50,0,49,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {110,0,49,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {49,0,-111,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {109,0,-111,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-51,0,-110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {-111,0,-110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {50,0,109,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
   {110,0,109,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {-50,0,110,  0,  -1,0,  0xFF,0xFF,0xFF,0xFF},
   {-110,0,110,  0,  0,0,  0xFF,0xFF,0xFF,0xFF},
}; //size of verts --- 48




static const Gfx N64LogoSmall_dl[] = {
   gsDPPipeSync(),
   gsDPSetCycleType(G_CYC_1CYCLE),
   gsSPTexture(0, 0, 0, 0, G_OFF),
   gsSPSetGeometryMode(G_SHADE | G_CULL_BACK),
   gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
   gsSPVertex(N64LogoSmall_vtx,48,0),

    gsSP1Triangle(0,1,2, 0),
    gsSP1Triangle(0,3,1, 0),
    gsSP1Triangle(4,5,6, 0),
    gsSP1Triangle(4,7,5, 0),
    gsSP1Triangle(8,9,10, 0),
    gsSP1Triangle(11,9,8, 0),
    gsSP1Triangle(12,13,14, 0),
    gsSP1Triangle(12,15,13, 0),
    gsSP1Triangle(16,17,18, 0),
    gsSP1Triangle(19,17,16, 0),
    gsSP1Triangle(20,21,22, 0),
    gsSP1Triangle(20,23,21, 0),
    gsSP1Triangle(24,25,26, 0),
    gsSP1Triangle(24,27,25, 0),
    gsSP1Triangle(28,29,30, 0),
    gsSP1Triangle(28,31,29, 0),
    gsSP1Triangle(16,18,32, 0),
    gsSP1Triangle(32,18,33, 0),
    gsSP1Triangle(34,9,35, 0),
    gsSP1Triangle(35,9,11, 0),
    gsSP1Triangle(36,29,31, 0),
    gsSP1Triangle(37,29,36, 0),
    gsSP1Triangle(34,12,14, 0),
    gsSP1Triangle(35,12,34, 0),
    gsSP1Triangle(32,21,23, 0),
    gsSP1Triangle(33,21,32, 0),
    gsSP1Triangle(25,38,39, 0),
    gsSP1Triangle(25,27,38, 0),
    gsSP1Triangle(15,40,13, 0),
    gsSP1Triangle(41,40,15, 0),
    gsSP1Triangle(42,30,43, 0),
    gsSP1Triangle(42,28,30, 0),
    gsSP1Triangle(26,44,24, 0),
    gsSP1Triangle(45,44,26, 0),
    gsSP1Triangle(46,22,47, 0),
    gsSP1Triangle(46,20,22, 0),
    gsSP1Triangle(41,6,40, 0),
    gsSP1Triangle(41,4,6, 0),
    gsSP1Triangle(43,19,42, 0),
    gsSP1Triangle(43,17,19, 0),
    gsSP1Triangle(28,13,40, 0),
    gsSP1Triangle(28,42,13, 0),
    gsSP1Triangle(47,3,46, 0),
    gsSP1Triangle(47,1,3, 0),
    gsSP1Triangle(20,24,44, 0),
    gsSP1Triangle(20,46,24, 0),
    gsSP1Triangle(10,45,8, 0),
    gsSP1Triangle(10,44,45, 0),
    gsSP1Triangle(31,14,36, 0),
    gsSP1Triangle(31,34,14, 0),
    gsSP1Triangle(27,23,38, 0),
    gsSP1Triangle(27,32,23, 0),
    gsSP1Triangle(32,3,0, 0),
    gsSP1Triangle(46,3,32, 0),
    gsSP1Triangle(36,19,16, 0),
    gsSP1Triangle(42,19,36, 0),
    gsSP1Triangle(34,6,5, 0),
    gsSP1Triangle(40,6,34, 0),
    gsSP1Triangle(10,38,44, 0),
    gsSP1Triangle(10,9,38, 0),
    gsSP1Triangle(17,37,18, 0),
    gsSP1Triangle(43,37,17, 0),
    gsSP1Triangle(33,1,47, 0),
    gsSP1Triangle(33,2,1, 0),
    gsSP1Triangle(4,35,7, 0),
    gsSP1Triangle(35,4,41, 0),
    gsSP1Triangle(39,8,45, 0),
    gsSP1Triangle(39,11,8, 0),
    gsSP1Triangle(32,24,46, 0),
    gsSP1Triangle(27,24,32, 0),
    gsSP1Triangle(34,28,40, 0),
    gsSP1Triangle(31,28,34, 0),
    gsSP1Triangle(41,12,35, 0),
    gsSP1Triangle(41,15,12, 0),
    gsSP1Triangle(7,11,39, 0),
    gsSP1Triangle(11,7,35, 0),
    gsSP1Triangle(25,45,26, 0),
    gsSP1Triangle(25,39,45, 0),
    gsSP1Triangle(47,21,33, 0),
    gsSP1Triangle(47,22,21, 0),
    gsSP1Triangle(18,2,33, 0),
    gsSP1Triangle(2,18,37, 0),
    gsSP1Triangle(29,43,30, 0),
    gsSP1Triangle(37,43,29, 0),
    gsSP1Triangle(38,9,5, 0),
    gsSP1Triangle(5,9,34, 0),
    gsSP1Triangle(36,16,0, 0),
    gsSP1Triangle(0,16,32, 0),
    gsSP1Triangle(14,13,36, 0),
    gsSP1Triangle(20,38,23, 0),
    gsSP1Triangle(36,13,42, 0),
    gsSP1Triangle(36,2,37, 0),
    gsSP1Triangle(44,38,20, 0),
    gsSP1Triangle(38,7,39, 0),
    gsSP1Triangle(0,2,36, 0),
    gsSP1Triangle(5,7,38, 0),
    gsSPEndDisplayList(),
};

void N64LogoSmall_mesh();
void N64LogoSmall_mesh(){
    current_mesh.size = 48;
    current_mesh.vertices = N64LogoSmall_vtx;
    current_mesh.settings = N64LogoSmall_dl;
};