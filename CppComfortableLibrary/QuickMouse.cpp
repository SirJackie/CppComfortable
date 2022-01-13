#include "QuickMouse.h"

#include <iostream>
#include <graphics.h>
#include <cmath>
#include "QuickKeyBoard.h"
#include "FocusingWindowGetter.h"

MouseState mouseState;

MouseState::MouseState(){
	x = 0;
	y = 0;
	deltaX = 0;
	deltaY = 0;
	lastX = NAN;
	lastY = NAN;
	lPressed = false;
	rPressed = false;
	mPressed = false;
}

void ShowMouseState(){
	cout << "MouseX: " << mouseState.x << "; MouseY: " << mouseState.y
		 << "; LMR: " << mouseState.lPressed << mouseState.mPressed << mouseState.rPressed
		 << "; DeltaX: " << mouseState.deltaX << "; DeltaY: " << mouseState.deltaY
		 << endl;
}

void UpdateMouseState(){
	mousepos(&(mouseState.x), &(mouseState.y));

	if(lastX == NAN || lastY == NAN){
		lastX = x;
		lastY = y;
		deltaX = 0;
		deltaY = 0;
	}
	else{
		deltaX = x - lastX;
		deltaY = y - lastY;
		// Prepare Last X & Y for the next frame
		lastX = x;
		lastY = y;
	}

	if(IsEGEWindowFocused()){
		mouseState.lPressed = IsKeyPressed(CSK_LButton);
		mouseState.rPressed = IsKeyPressed(CSK_RButton);
		mouseState.mPressed = IsKeyPressed(CSK_MButton);
	}
}

