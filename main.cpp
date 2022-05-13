#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"
#include "./CppComfortableLibrary/QuickKeyBoard.h"
#include "./CppComfortableLibrary/QuickMouse.h"
#include "./CppComfortableLibrary/WindowHelper.h"
#include <windows.h>

#define WIDTH 1024
#define HEIGHT 576

int x = 0;
int y = 0;
int speed = 1;

void setup() {
	;
}

void loop() {
	SaveScreenWidthForSetPixel(WIDTH);
	SetPixel(x, y, CSRGB(255, 0, 0));

	if(IsKeyPressed(CSK_W)){
		y -= speed;
	}
	if(IsKeyPressed(CSK_S)){
		y += speed;
	}
	if(IsKeyPressed(CSK_A)){
		x -= speed;
	}
	if(IsKeyPressed(CSK_D)){
		x += speed;
	}
}

int main() {
	ConstructWindow(WIDTH, HEIGHT);

	PreSetup();
	setup();
	PostSetup();

	for LifeCycle {
		UpdateMouseState();
		PreLoop();
		loop();
		PostLoop();
	}

	DestructWindow();
}

