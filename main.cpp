#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"

#define WIDTH 1024
#define HEIGHT 576

void setup(){
	setfillcolor(RED);
	bar(10, 10, 100, 100);
}

void loop (){
	;
}

int main() {
	CreateWindow(WIDTH, HEIGHT);

	PreSetup();
	setup();
	PostSetup();

	for LifeCycle {
		loop();
		PostLoop();
	}

	DestroyWindow();
}

