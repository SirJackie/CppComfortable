#ifndef __CppComfortable_UILifeCycle_H__
#define __CppComfortable_UILifeCycle_H__

#define SHOW_CONSOLE
#include <graphics.h>

#include <iostream>
using std::cout;
using std::endl;

#define TARGET_FPS 60

// Swapping Related Definitions
extern int cpulBackImage;
#define SwapImage() (cpulBackImage=!cpulBackImage)
#define SetFrontImage() (setvisualpage(!cpulBackImage))
#define SetBackImage() (setactivepage(cpulBackImage))

// Address Getting Related Definitions
extern unsigned char* frameBuffer;
#define GetCurrentBuffer() ( (unsigned char*)(getbuffer(gettarget())) )
#define UpdateBufferAddr() (frameBuffer=GetCurrentBuffer())

// Setup and Loop Pre and Post Processing Definitions
#define PreSetup() { SetFrontImage(), SetBackImage(), UpdateBufferAddr(); }
#define PostSetup() { SwapImage(), SetFrontImage(), SetBackImage(), cleardevice(), delay_fps(TARGET_FPS); }
#define PreLoop() { UpdateBufferAddr(); }
#define PostLoop() { SwapImage(), SetFrontImage(), SetBackImage(), cleardevice(); }

// Window Creating Related Definitions
#define ConstructWindow(width, height) (initgraph(width, height, INIT_RENDERMANUAL))
#define DeconstructWindow() (closegraph())

// Debug Related Definitions
#define WatchCurrentBufferState() { cout << "Front: " << !cpulBackImage << "; Back: " << cpulBackImage << endl; }

// For-Statement Simplyfying Definitions
#define FitFPS() (delay_fps(TARGET_FPS))
#define IsLifeCycleOver() (is_run())
#define LifeCycle ( ; IsLifeCycleOver(); FitFPS() )

#endif

