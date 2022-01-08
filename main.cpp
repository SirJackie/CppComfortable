#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"

#define WIDTH 1024
#define HEIGHT 576

void setup() {
	;
}

void loop() {
	float sw = WIDTH;
	float sh = HEIGHT;
	float ar = sw / sh;
	
	float x0 = -1.77777f, y0 = 1.0f, x1 = 1.77777f, y1 = 1.0f, x2 = -1.77777f, y2 = -1.0f, x3 = 1.77777f, y3 = -1.0f;
	
	float x0p = FPube(x0, ar, sw);
	float x1p = FPube(x1, ar, sw);
	float x2p = FPube(x2, ar, sw);
	float x3p = FPube(x3, ar, sw);
	
	float y0p = FPube(y0, sh);
	float y1p = FPube(y1, sh);
	float y2p = FPube(y2, sh);
	float y3p = FPube(y3, sh);
	
	DrawPoint(x0p, y0p, 5, 255, 255, 255, WIDTH, HEIGHT);
	DrawPoint(x1p, y1p, 5, 255, 255, 255, WIDTH, HEIGHT);
	DrawPoint(x2p, y2p, 5, 255, 255, 255, WIDTH, HEIGHT);
	DrawPoint(x3p, y3p, 5, 255, 255, 255, WIDTH, HEIGHT);
}

int main() {
	ConstructWindow(WIDTH, HEIGHT);

	PreSetup();
	setup();
	PostSetup();

	for LifeCycle {
		PreLoop();
		loop();
		PostLoop();
	}

	DeconstructWindow();
}

