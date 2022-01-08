#define SHOW_CONSOLE
#include <graphics.h>
#include <iostream>
using namespace std;

#define WIDTH 1024
#define HEIGHT 576

void loop(){
	cout << "Looping..." << endl;
}

int main() {
	
	initgraph(WIDTH, HEIGHT, INIT_RENDERMANUAL);
	
	PIMAGE buffer1 = gettarget();
	PIMAGE buffer2 = newimage(WIDTH, HEIGHT);
	
	PIMAGE* frontBuffer = &buffer1;
	PIMAGE* backBuffer  = &buffer2;
	PIMAGE* tmpBufPtr = nullptr;
	
	for( ; is_run(); delay_fps(60) ) {
		loop();
		settarget(*backBuffer);
		tmpBufPtr = backBuffer;
		backBuffer = frontBuffer;
		frontBuffer = tmpBufPtr;
	}

	closegraph();
	
}

