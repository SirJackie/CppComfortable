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
			frameBuffer[(y * WIDTH + x) * 4 + 0] = (x%2) * 255;
			frameBuffer[(y * WIDTH + x) * 4 + 1] = (x%2) * 255;
			frameBuffer[(y * WIDTH + x) * 4 + 2] = (x%2) * 255;
			frameBuffer[(y * WIDTH + x) * 4 + 3] = 255;
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

