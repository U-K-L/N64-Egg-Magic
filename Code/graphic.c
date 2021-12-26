#include <nusys.h>
#include "config.h"


//View port, device coordinate system.
//Top left (0,0), bottom right (320,240)
static Vp viewport = {
  SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, //Size of viewport.
  SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, //Position of the center.
};

Gfx const rspinit_dl[] = {
    gsSPViewport(&viewport), //Set viewport.
    gsSPClearGeometryMode(0x00000000), //What each bit means: http://n64devkit.square7.ch/n64man/gsp/gSPClearGeometryMode.htm
    gsSPTexture(0, 0, 0, 0, G_OFF), //Disable textures.
    gsSPEndDisplayList(), //Ends the display list!

};

//This is the static definition of the initial state.
//Note gsXY vs gXY, the former is a static definition. ie gsSPVertex (static) vs gSPVertex (dynamic)
Gfx const rdpinit_dl[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WD, SCREEN_HT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};


void RCPInit(Gfx *glistp)
{
    gSPSegment(glistp++, 0, 0); //initialize segment register. Keeps track of display list.
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rspinit_dl));
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rdpinit_dl));
}

void gfxClearCfb(void)
{
  /* Clear the Z-buffer  */
  gDPSetDepthImage(glistp++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
  gDPSetCycleType(glistp++, G_CYC_FILL);
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b,SCREEN_WD,
		   OS_K0_TO_PHYSICAL(nuGfxZBuffer));
  gDPSetFillColor(glistp++,(GPACK_ZDZ(G_MAXFBZ,0) << 16 |
			       GPACK_ZDZ(G_MAXFBZ,0)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
  gDPPipeSync(glistp++);
  
    /* Clear the frame buffer  */
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD,
		   osVirtualToPhysical(nuGfxCfb_ptr));
  gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16 | 
				GPACK_RGBA5551(0, 0, 0, 1)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
  gDPPipeSync(glistp++);
}
