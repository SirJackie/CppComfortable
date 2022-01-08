#ifndef __CppComfortable_UILifeCycle_H__
#define __CppComfortable_UILifeCycle_H__

#define SHOW_CONSOLE
#include <graphics.h>

#include <iostream>
using std::cout;
using std::endl;

#define TARGET_FPS 60

int cpulBackImage = 0;

#define SwapImage() (cpulBackImage=!cpulBackImage)
#define SetFrontImage() (setvisualpage(!cpulBackImage))
#define SetBackImage() (setactivepage(cpulBackImage))

#define PreSetup() { SetFrontImage(), SetBackImage(); }
#define PostSetup() { SwapImage(), SetFrontImage(), SetBackImage(), delay_fps(TARGET_FPS); }
#define PostLoop() { SwapImage(), SetFrontImage(), SetBackImage(); }

#define ConstructWindow(width, height) (initgraph(width, height, INIT_RENDERMANUAL))
#define DeconstructWindow() (closegraph())

#define WatchCurrentBufferState() { cout << "Front: " << !cpulBackImage << "; Back: " << cpulBackImage << endl; }

#define FitFPS() (delay_fps(TARGET_FPS))
#define IsLifeCycleOver() (is_run())
#define LifeCycle ( ; IsLifeCycleOver(); FitFPS() )

#endif

