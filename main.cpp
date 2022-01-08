#define SHOW_CONSOLE
#include <graphics.h>
#include <iostream>
using namespace std;

#define WIDTH 1024
#define HEIGHT 576

void ShowPtrAddr(void* ptr){
	cout << (unsigned long long) ptr << endl;
}

void setup(){
	setfillcolor(RED);
	bar(10, 10, 100, 100);
}

void loop (){
	;
}

int frontBuffer = 0;
#define SwapBuffer() (frontBuffer=!frontBuffer)
#define SetFrontBuffer() (setvisualpage(frontBuffer))
#define SetBackBuffer() (setactivepage(!frontBuffer))

inline static void SwapAndSet(){
	SwapBuffer();
	SetFrontBuffer();
	SetBackBuffer();
}

int main() {
	initgraph(WIDTH, HEIGHT, INIT_RENDERMANUAL);
	
	setup();
	SwapAndSet();

	for( ; is_run(); delay_fps(60) ) {
		loop();
		SwapAndSet();
	}

	closegraph();
}

