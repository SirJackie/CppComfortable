#ifndef __CppComfortable_UILifeCycle_H__
#define __CppComfortable_UILifeCycle_H__

#define SHOW_CONSOLE
#include <graphics.h>

#include <iostream>
using std::cout;
using std::endl;

int cpulBackImage = 0;

#define SwapImage() (cpulBackImage=!cpulBackImage)
#define SetFrontImage() (setvisualpage(!cpulBackImage))
#define SetBackImage() (setactivepage(cpulBackImage))

#define Swappi() { SwapImage(), SetFrontImage(), SetBackImage(); }
#define PreSetup() { SetFrontImage(), SetBackImage(); }
#define PostSetup() { SwapImage(), SetFrontImage(), SetBackImage(), delay_fps(1); }

#define WatchCurrentBufferState() { cout << "Front: " << !cpulBackImage << "; Back: " << cpulBackImage << endl; }

#endif

