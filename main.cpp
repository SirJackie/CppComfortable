#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"

#define WIDTH 1024
#define HEIGHT 576

unsigned int position = 0;

void setup() {
	;
}

void loop() {
	DrawPoint(position, position / 2, 5, 255, 255, 255, WIDTH, HEIGHT);
	position += 1;
	if(position >= HEIGHT * 2 || position >= WIDTH){
		position = 0;
	}
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

