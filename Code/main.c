/*
  Creator: U.K.L.
  Starts the main process to begin the game.
*/

#include <nusys.h>
#include "stages.h"
#include "config.h"

static void RetraceCallback(int pendingTasks);
void mainproc(void *dummy)
{
  nuGfxInit();//Initializes the graphics thread.
  Stage00_Init();
  nuGfxFuncSet((NUGfxFunc)RetraceCallback); //Sets function to be called each screen refresh.
  nuGfxDisplayOn(); //Turns the screen on.
  while(1);
}

//This is synchronous with the graphics thread. Is called by the graphics thread.
void RetraceCallback(int pendingTasks)
{
  Stage00_Update(); //Used to update every time graphics thread executes.

  //If the amount of remaining tasks on the graphics thread is done.
  if(pendingTasks <= 0)
  {
    Stage00_UpdateFrame(); //Handles gameplay.
    Stage00_Draw(); //Handles custom graphics.
  }
    
}