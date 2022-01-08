#include "FrameBufferTools.h"

void FillRectangle(int x0, int y0, int x1, int y1, char r, char g, char b, int screenWidth){
	for(int y = y0; y < y1; y++){
		for(int x = x0; x < x1; x++){
			frameBuffer[(y * screenWidth + x) * 4 + 0] = r;
			frameBuffer[(y * screenWidth + x) * 4 + 1] = g;
			frameBuffer[(y * screenWidth + x) * 4 + 2] = b;
		}
	}
}

