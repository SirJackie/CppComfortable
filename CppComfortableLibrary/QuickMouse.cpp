#include "QuickMouse.h"

MouseState mouseState;

MouseState::MouseState(){
	x = 0;
	y = 0;
	lPressed = false;
	rPressed = false;
	mPressed = false;
}

void ShowMouseState(){
	cout << "MouseX: " << mouseState.x << "; MouseY: " << mouseState.y << "; LMR: " << mouseState.lPressed << mouseState.mPressed << mouseState.rPressed << endl;
}

void UpdateMouseState(){
	mousepos(&(mouseState.x), &(mouseState.y));
	mouseState.lPressed = IsKeyPressed(CSK_LButton);
	mouseState.rPressed = IsKeyPressed(CSK_RButton);
	mouseState.mPressed = IsKeyPressed(CSK_MButton);
}

