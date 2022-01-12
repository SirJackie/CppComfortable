#ifndef __CppComfortable_QuickMouse_H__
#define __CppComfortable_QuickMouse_H__

#include <iostream>
#include <graphics.h>
#include "QuickKeyBoard.h"
using std::cout;
using std::endl;

class MouseState{
public:
	int x;
	int y;
	bool lPressed;
	bool mPressed;
	bool rPressed;
	
	// Constructor
	MouseState();
};

extern MouseState mouseState;

void ShowMouseState();
void UpdateMouseState();

#endif

