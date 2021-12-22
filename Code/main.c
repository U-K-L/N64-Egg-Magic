/*
  Creator: U.K.L.
  Starts the main process to begin the game.
*/

#include <nusys.h>
#include "stages.h"

static void RetraceCallback(int pendingTasks);
void mainproc(void *dummy)
{
  
  nuGfxInit();//Initializes the graphics thread.
  Stage00_Init();
  nuGfxFuncSet((NUGfxFunc)RetraceCallback); //Sets function to be called each screen refresh.
  nuGfxDisplayOn(); //Turns the screen on.
  while(1);
}

//This is called at the start of a screen refresh.
void RetraceCallback(int pendingTasks)
{
  Stage00_Update(); //Used to update parallel to main thread.
  //If the amount of remaining tasks nearly finished.
  if(pendingTasks < 1)
  {
    Stage00_UpdateFrame(); //Handles gameplay.
    Stage00_Draw(); //Handles custom graphics.
  }
    
}