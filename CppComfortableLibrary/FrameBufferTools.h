#ifndef __CppComfortable_FrameBufferTools_H__
#define __CppComfortable_FrameBufferTools_H__

#include "UILifeCycle.h"
#include "MathTools.h"

void FillRectangle(int x0, int y0, int x1, int y1, char r, char g, char b, int screenWidth);
void DrawPoint(int x, int y, int radius, char r, char g, char b, int screenWidth, int screenHeight);

#define CSRGB(r, g, b) ( r << 16 | g << 8 | b | 0xFF << 24 )
#define SetPixel(x, y, screenWidth, color) ( *( (int*)(frameBuffer + (((y * screenWidth) + x) * 4)) ) = (int)color )

#endif

