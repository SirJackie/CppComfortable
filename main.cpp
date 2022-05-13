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

void setup() {
	;
}

void loop() {
	SetPixel(x, y, WIDTH, CSRGB(255, 0, 0));
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

