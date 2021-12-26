#include <nusys.h>
#include "stages.h"
#include "config.h"
#include "systemUtil.h"
#include "gu.h"
#include <math.h>
#include "graphic.h"
#include <assert.h>

void CreateMesh(Dynamic* dynamicp, Mesh mesh);
Dynamic      gfx_dynamic;
Mesh         current_mesh;


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

  glistp = glist;

  RCPInit(glistp);

  //Clears Z buffer.
  gfxClearCfb();

  guOrtho(&gfx_dynamic.projection,
	  -(float)SCREEN_WD/2.0F, (float)SCREEN_WD/2.0F,
	  -(float)SCREEN_HT/2.0F, (float)SCREEN_HT/2.0F,
	  1.0F, 10.0F, 1.0F);
  guRotate(&gfx_dynamic.modeling, 0.0F, 0.0F, 0.0F, 1.0F);
  test_mesh();

  CreateMesh(&gfx_dynamic, current_mesh);


  /* End the construction of the display list  */
  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  /* Check if all are put in the array  */
  assert(glistp - glist < GLIST_LENGTH);
  /* Activate the RSP task.  Switch display buffers at the end of the task. */
  nuGfxTaskStart(glist,
		 (s32)(glistp - glist) * sizeof (Gfx),
		 NU_GFX_UCODE_F3DEX , NU_SC_SWAPBUFFER);
    /*
    glistp = glist;
    RCPInit(glistp);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gSPVertex(glistp++, &(triangle_vtx[0]), 3, 0); 
    gSP1Triangle(glistp++, 0, 1, 2, 0);
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx),
                NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
*/
/*
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
    colorB = (u8)floor(sinf(time)*255);
    colorR = (u8)floor(cosf(time)*255);
    offsetX = (int)floor(cosf(time*speed)*radius);
    offsetY = (int)floor(sinf(time*speed)*radius);
    glistp = glist;
    RCPInit(glistp);
    /*
    if(time > 5)
    {
        ClearBackground(colorR, colorR, colorB);
        gDPSetCycleType(glistp++, G_CYC_FILL);
        gDPSetFillColor(glistp++, (GPACK_RGBA5551(255, 0, 255, 1) << 16 |
                           GPACK_RGBA5551(255, 0, 255, 1)));
        gDPFillRectangle(glistp++, offsetX+x-width, offsetY+y-height, offsetX+x+width, offsetY+y+height);
    }
    else if(time > 2.55f)
    {
        colorB = (colorB > 200)*255;
        ClearBackground(colorB, colorB, colorB);
    }else
    {
       ClearBackground(0, 0, 0); 
    }
        
        /*
  guOrtho(&gfx_dynamic.projection,
	  -(float)SCREEN_WD/2.0F, (float)SCREEN_WD/2.0F,
	  -(float)SCREEN_HT/2.0F, (float)SCREEN_HT/2.0F,
	  1.0F, 10.0F, 1.0F);
  guRotate(&gfx_dynamic.modeling, 0.0F, 0.0F, 0.0F, 1.0F);


    gSPVertex(glistp++, &(triangle_vtx[0]), 3, 0); 
    gSP1Triangle(glistp++, 0, 1, 2, 0);
            // Vertex array length
        gSPVertex(glistp++,&(shade_vtx[0]),8, 0);

        gSP2Triangles(glistp++,0,1,5,0,5,2,6,0);
        gSP1Triangle(glistp++,1,5,2,0);
        gSP2Triangles(glistp++,0,3,4,0,3,4,7,0);
        gSP2Triangles(glistp++,3,2,6,0,3,6,7,0);
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx),
                NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);


    gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
		G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
  gSPVertex(glistp++,&(shade_vtx[0]),4, 0);
  gDPPipeSync(glistp++);
  gDPSetCycleType(glistp++,G_CYC_1CYCLE);
  gDPSetRenderMode(glistp++,G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
  gSPClearGeometryMode(glistp++,0xFFFFFFFF);
  gSPSetGeometryMode(glistp++,G_SHADE| G_SHADING_SMOOTH);
  gSP2Triangles(glistp++,0,1,2,0,0,2,3,0);
    if(time > 5)
        DisplayText("...and wonder if we'll ever get the chance to kill him.");
    else if(time > 2.55f)
        DisplayText(" I often think about the god who blessed us with this cryptic puzzle…");
    else if(time > 1.0f)
        DisplayText("We are perpetually trapped in a never ending spiral of life and death.");
    else
        DisplayText("Everything that lives is designed to end.");
        */
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

void DisplayText(const char*text)
{
    //From Hello world example
    nuDebConDisp(NU_SC_SWAPBUFFER); // Displays the console window. NU_SC_SWAPBUFFER = Swap frame buffer
    nuDebConClear(NU_DEB_CON_WINDOW0); // Clears the console window. NU_DEB_CON_WINDOW0 = Window 0
    nuDebConTextColor(NU_DEB_CON_WINDOW0, NU_DEB_CON_TEXT_LIGHTBLUE); // Changes the color of text displayed in the console window
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 0, 13); // Sets the position where text will be displayed inside console window
    nuDebConCPuts(NU_DEB_CON_WINDOW0, text); // Outputs the character string to console window
    //------------------------------

}

void CreateMesh(Dynamic* dynamicp, Mesh mesh)
{
    gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->projection)),
        G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
    gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
        G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
     gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(mesh.settings));
     

}