#define SHOW_CONSOLE
#include <graphics.h>
#include <iostream>
using namespace std;

#define WIDTH 1024
#define HEIGHT 576

void setup(PIMAGE& image, char* buffer){
	setfillcolor(RED, image);
	bar(10, 10, 100, 100, image);
}

void loop (PIMAGE& image, char* buffer){
	cout<<(unsigned long long)((void*)buffer)<<endl;
//	setfillcolor(RED, image);
//	bar(20, 20, 110, 110, image);
}

int main() {

	initgraph(WIDTH, HEIGHT, INIT_RENDERMANUAL);

	PIMAGE buffer1 = gettarget();
	PIMAGE buffer2 = newimage(WIDTH, HEIGHT);

	PIMAGE* frontBuffer = &buffer1;
	PIMAGE* backBuffer  = &buffer2;
	PIMAGE* tmpBufPtr = nullptr;

	setup( (*backBuffer), (char*)getbuffer((*backBuffer)) );

	// Swap Buffer
	tmpBufPtr = backBuffer;
	backBuffer = frontBuffer;
	frontBuffer = tmpBufPtr;

	for( ; is_run(); delay_fps(60) ) {
		loop( (*backBuffer), (char*)getbuffer((*backBuffer)) );
		settarget(*backBuffer);

		// Swap Buffer
		tmpBufPtr = backBuffer;
		backBuffer = frontBuffer;
		frontBuffer = tmpBufPtr;
	}

	closegraph();

}

