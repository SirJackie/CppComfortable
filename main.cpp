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

int xStart = 0;
int yStart = 0;
int speed = 10;

void setup() {
	SaveScreenWidthForSetPixel(WIDTH);
	SaveScreenHeightForSafeSetPixel(HEIGHT);
}

void loop() {
	int xEnd = xStart + 500;
	int yEnd = yStart + 500;
	for (int y = yStart; y < yEnd; y++){
		for (int x = xStart; x < xEnd; x++){
			SafeSetPixel(x, y, CSRGB(255, 0, 0));
		}
	}
	
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

