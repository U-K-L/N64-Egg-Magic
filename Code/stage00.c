#include <nusys.h>
#include "stages.h"
#include "config.h"
#include "systemUtil.h"
#include "gu.h"
#include <math.h>

void ClearBackground(u8 r, u8 g, u8 b);
void Stage00_Init()
{

}

//Updates for every tick.
void Stage00_Update()
{
  time += 0.01f;
}

//Updates for every new frame.
void Stage00_UpdateFrame()
{
  
}

void Stage00_Draw()
{
    int x =  SCREEN_WD/2;
    int y =  SCREEN_HT/2;
    int radius = 70;
    int offsetX = 0;
    int offsetY = 0;
    int width = 16;
    int height = 16;
    float speed = 3.0f;
    u8 colorB = 0;
    u8 colorR = 0;
    glistp = glist;
    RCPInit(glistp);
    colorB = (u8)floor(sinf(time)*255);
    colorR = (u8)floor(cosf(time)*255);
    offsetX = (int)floor(cosf(time*speed)*radius);
    offsetY = (int)floor(sinf(time*speed)*radius);
    ClearBackground(colorR, colorR, colorB);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(255, 0, 255, 1) << 16 |
                           GPACK_RGBA5551(255, 0, 255, 1)));
    gDPFillRectangle(glistp++, offsetX+x-width, offsetY+y-height, offsetX+x+width, offsetY+y+height);

    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx),
                NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
}

void ClearBackground(u8 r, u8 g, u8 b)
{
    //set framebuffer to a single color
    gDPSetCycleType(glistp++, G_CYC_FILL); 
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD,
                 osVirtualToPhysical(nuGfxCfb_ptr));
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);
}