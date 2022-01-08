#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"

#define WIDTH 1024
#define HEIGHT 576

unsigned char color = 0;

void setup() {
	;
}

void loop () {
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			frameBuffer[(y * WIDTH + x) * 3 + 0] = color;
			frameBuffer[(y * WIDTH + x) * 3 + 1] = color;
			frameBuffer[(y * WIDTH + x) * 3 + 2] = color;
		}
	}
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

