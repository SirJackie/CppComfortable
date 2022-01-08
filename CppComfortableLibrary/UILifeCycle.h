#ifndef __CppComfortable_UILifeCycle_H__
#define __CppComfortable_UILifeCycle_H__

#define SHOW_CONSOLE
#include <graphics.h>

#include <iostream>
using std::cout;
using std::endl;

#define TARGET_FPS 1

int cpulBackImage = 0;

#define SwapImage() (cpulBackImage=!cpulBackImage)
#define SetFrontImage() (setvisualpage(!cpulBackImage))
#define SetBackImage() (setactivepage(cpulBackImage))

#define Swappi() { SwapImage(), SetFrontImage(), SetBackImage(); }
#define PreSetup() { SetFrontImage(), SetBackImage(); }
#define PostSetup() { SwapImage(), SetFrontImage(), SetBackImage(), delay_fps(TARGET_FPS); }

#define WatchCurrentBufferState() { cout << "Front: " << !cpulBackImage << "; Back: " << cpulBackImage << endl; }

#define FitFPS() (delay_fps(TARGET_FPS))
#define IsLifeCycleOver() (is_run())
#define LifeCycle ( ; IsLifeCycleOver(); FitFPS() )

#endif

