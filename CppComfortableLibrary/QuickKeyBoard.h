#ifndef __CppComfortable_QuickKeyBoard_H__
#define __CppComfortable_QuickKeyBoard_H__

#include <Windows.h>

#define IsKeyPressed(VK_NONAME) ( (GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0 )

#endif

