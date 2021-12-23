#include <nusys.h>
#include "config.h"

typedef struct {
	short   view_scale[4]; 
	short   view_transformation[4];
	long long int   force_structure_alignment;
}
//View port, device coordinate system.
//Top left (0,0), bottom right (320,240)
static Vp viewport = {
  SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, //Size of viewport.
  SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, //Position of the center.
};

Gfx rspinit_dl[] = {
    gsSPViewport(&viewport), //Set viewport.
    gsSPClearGeometryMode(0x00000000), //What each bit means: http://n64devkit.square7.ch/n64man/gsp/gSPClearGeometryMode.htm
    gsSPTexture(0, 0, 0, 0, G_OFF), //Disable textures.
    gsSPEndDisplayList(), //Ends the display list!
};

void RCPInit(GFX *glistp)
{
    gSPSegment(glistp++, 0, 0); //initialize segment register. Keeps track of display list.
}

