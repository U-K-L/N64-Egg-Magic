#include <nusys.h>
#include "stages.h"
#include "config.h"
#include "systemUtil.h"
#include "gu.h"
#include <math.h>
#include "graphic.h"
#include <assert.h>

//Models:
#include "../Models/Monkey.h"
#include "../Models/Cylinder.h"
#include "../Models/N64Logo.h"
#include "../Models/PlyCube.h"
#include "../Models/N64LogoSmallColor.h"
#include "../Models/N64LogoSmall.h"
#include "../Models/N64LogoUV1.h"

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

  RCPInit();
  

  //Clears Z buffer.
  gfxClearCfb();


  /* The set of projection modeling matrices  */
  guRotate(&gfx_dynamic.modeling, 0.0F, 0.0F, 0.0F, 1.0F);

  /* Draw a square  */
 guPerspective(&gfx_dynamic.projection, &perspNorm, 60, 320.0f / 240.0f,
        1, 1024, 1.0F);

    guLookAt(&gfx_dynamic.camera,            //
    200.0f, 200.0f, 700.0f, // eye
    0.0f, 0.0f, 0.0f,       // look at
    0.0f, 1.0f, 0.0f);      // up
    CreateMesh(&gfx_dynamic, current_mesh);

    N64LogoSmallColor_mesh();
    
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(current_mesh.settings));

  
    /* End the construction of the display list  */
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
        /* Check if all are put in the array  */
    assert(glistp - glist < GLIST_LENGTH);
    /* Activate the RSP task.  Switch display buffers at the end of the task. */
    nuGfxTaskStart(glist,
            (s32)(glistp - glist) * sizeof (Gfx),
            NU_GFX_UCODE_F3DEX2_REJ , NU_SC_SWAPBUFFER);
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
    
    //Set the projection matrix of the current screen of the N64
    gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->projection)),
        G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);

    //Set the current camera.
    gSPMatrix(glistp++, K0_TO_PHYS(&(dynamicp->camera)),
        G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);

    //Set the model matrix.
    gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
        G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);

    guRotate(&gfx_dynamic.rotate_x, time*10, 0.0F, 1.0F, 0.0F);
    gSPMatrix(glistp++, K0_TO_PHYS(&(gfx_dynamic.rotate_x)),
        G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);

}

/* The vertex coordinate  */
static Vtx shade_vtxDEBUG[] =  {
        {        -64,  64, -5, 0, 0, 0, 0, 0xff, 0, 0xff	},
        {         64,  64, -5, 0, 0, 0, 0, 0, 0, 0xff	},
        {         64, -64, -5, 0, 0, 0, 0, 0, 0xff, 0xff	},
        {        -64, -64, -5, 0, 0, 0, 0xff, 0, 0, 0xff	},
};

/* Draw a square  */
void shadetri(Dynamic* dynamicp)
{
    /*
  gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->projection)),
		G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
  gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
		G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
*/
  gSPVertex(glistp++,&(shade_vtxDEBUG[0]),4, 0);

  gDPPipeSync(glistp++);
  gDPSetCycleType(glistp++,G_CYC_1CYCLE);
  gDPSetRenderMode(glistp++,G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
  gSPClearGeometryMode(glistp++,0xFFFFFFFF);
  gSPSetGeometryMode(glistp++,G_SHADE| G_SHADING_SMOOTH);

  gSP2Triangles(glistp++,0,1,2,0,0,2,3,0);
}