#ifndef N64_STAGES_H
#define N64_STAGES_H
#include <nusys.h>
#include "stages.h"
#include "config.h"
#include "systemUtil.h"
#include "gu.h"
#include <math.h>
#include "graphic.h"
#include <assert.h>

	void Stage00_Init();
	void Stage00_Update();
    void Stage00_UpdateFrame();
	void Stage00_Draw();
	void DisplayText(const char*text);
	void ClearBackground(u8 r, u8 g, u8 b);
	void CreateMesh(Dynamic* dynamicp, Mesh mesh);
	Dynamic      gfx_dynamic;
	Mesh         current_mesh;
	Mesh         current_mesh2;
	u16 perspNorm;

 
#endif
