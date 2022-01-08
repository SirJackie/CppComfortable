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
	initgraph(WIDTH, HEIGHT, INIT_RENDERMANUAL);

	PreSetup();
	WatchCurrentBufferState();
	setup();
	PostSetup();

	for( ; is_run(); delay_fps(1) ) {
		WatchCurrentBufferState();
		loop();
		Swappi();
	}

	closegraph();
}

