#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"
#include "./CppComfortableLibrary/QuickKeyBoard.h"
#include "./CppComfortableLibrary/QuickMouse.h"
#include "./CppComfortableLibrary/WindowHelper.h"
#include "./CppComfortableLibrary/UITools.h"
#include <windows.h>

#define WIDTH 1024
#define HEIGHT 576

int xStart = 0;
int yStart = 0;
int xEnd = 500;
int yEnd = 100;
int speed = 3;

void setup() {
	SaveScreenWidthForSetPixel(WIDTH);
	SaveScreenHeightForSafeSetPixel(HEIGHT);
}

void loop() {
	DrawBresenhamLine(xStart, yStart, xEnd, yEnd, CSRGB(255, 0, 0));

	if(IsKeyPressed(CSK_W)){
		yStart -= speed;
	}
	if(IsKeyPressed(CSK_S)){
		yStart += speed;
	}
	if(IsKeyPressed(CSK_A)){
		xStart -= speed;
	}
	if(IsKeyPressed(CSK_D)){
		xStart += speed;
	}
	
	if(IsKeyPressed(CSK_I)){
		yEnd -= speed;
	}
	if(IsKeyPressed(CSK_K)){
		yEnd += speed;
	}
	if(IsKeyPressed(CSK_J)){
		xEnd -= speed;
	}
	if(IsKeyPressed(CSK_L)){
		xEnd += speed;
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

