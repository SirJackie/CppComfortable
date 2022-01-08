#include "FrameBufferTools.h"

void FillRectangle(int x0, int y0, int x1, int y1, char r, char g, char b, int screenWidth){
	for(int y = y0; y < y1; y++){
		unsigned char* bufStart = frameBuffer + (((y * screenWidth) + x0) * 4);
		for(int x = x0; x < x1; x++){
			bufStart[0] = b;
			bufStart[1] = g;
			bufStart[2] = r;
			bufStart += 4;
		}
	}
}

void DrawPoint(int x, int y, int radius, char r, char g, char b, int screenWidth, int screenHeight){
	int x0 = clamp(0, x-radius, screenWidth);
	int x1 = clamp(0, x+radius, screenWidth);
	int y0 = clamp(0, y-radius, screenHeight);
	int y1 = clamp(0, y+radius, screenHeight);
	FillRectangle(x0, y0, x1, y1, r, g, b, screenWidth);
}

