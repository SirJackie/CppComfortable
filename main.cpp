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

	PreSwappi();
	setup();

	for( ; is_run(); delay_fps(1) ) {
		cout << cpulFrontImage << endl;
		loop();
		Swappi();
	}

	closegraph();
}

