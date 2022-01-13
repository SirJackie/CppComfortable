#ifndef __CppComfortable_QuickMouse_H__
#define __CppComfortable_QuickMouse_H__

#include <iostream>
#include <graphics.h>
#include <cmath>
#include "QuickKeyBoard.h"
#include "FocusingWindowGetter.h"

using std::cout;
using std::endl;

class MouseState{
public:
	int x;
	int y;
	int deltaX;
	int deltaY;
	int lastX;
	int lastY;

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

