#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"

#define WIDTH 1024
#define HEIGHT 576

#define GetCurrentBuffer() ( (unsigned char*)(getbuffer(gettarget())) )

unsigned char* frameBuffer;
#define UpdateBufferAddr() (frameBuffer=GetCurrentBuffer())

unsigned char color = 0;

void setup(){
	;
}

void loop (){
	setfillcolor(EGERGB(color, color, color));
	bar(0, 0, WIDTH, HEIGHT);
	color += 1;
	ShowPtrAddr(frameBuffer);
}

int main() {
	ConstructWindow(WIDTH, HEIGHT);

	PreSetup();
	setup();
	PostSetup();

	for LifeCycle {
		UpdateBufferAddr();
		loop();
		PostLoop();
	}

	DeconstructWindow();
}

