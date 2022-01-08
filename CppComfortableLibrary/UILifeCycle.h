#ifndef __CppComfortable_UILifeCycle_H__
#define __CppComfortable_UILifeCycle_H__

#define SHOW_CONSOLE
#include <graphics.h>

int cpulFrontImage = 0;

#define SwapImage() (cpulFrontImage=!cpulFrontImage)
#define SetFrontImage() (setvisualpage(cpulFrontImage))
#define SetBackImage() (setactivepage(!cpulFrontImage))

#define PreSwappi() { SetFrontImage(), SetBackImage(); }
#define Swappi() { SwapImage(), SetFrontImage(), SetBackImage(); }

#endif

