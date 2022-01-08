#include "FrameBufferTools.h"

void FillRectangle(int x0, int y0, int x1, int y1, char r, char g, char b, int screenWidth){
	for(int y = y0; y < y1; y++){
		unsigned char* bufStart = frameBuffer + ((y * screenWidth) * 4);
		for(int x = x0; x < x1; x++){
			bufStart[0] = b;
			bufStart[1] = g;
			bufStart[2] = r;
			bufStart += 4;
		}
	}
}

