#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"

#define WIDTH 1024
#define HEIGHT 576

unsigned char color = 0;

void setup() {
	;
}

void loop() {
	FillRectangle(0, 0, WIDTH, HEIGHT, color, color, color, WIDTH);
	color += 1;
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

