#ifndef __CppComfortable_FrameBufferTools_H__
#define __CppComfortable_FrameBufferTools_H__

#include "UILifeCycle.h"
#include "MathTools.h"

void FillRectangle(int x0, int y0, int x1, int y1, char r, char g, char b, int screenWidth);
void DrawPoint(int x, int y, int radius, char r, char g, char b, int screenWidth, int screenHeight);

#define CSRGB(r, g, b) ( ((r&255) << 16) + ((g&255) << 8) + (b&255) )

extern int screenWidthSaver;
#define SaveScreenWidthForSetPixel(screenWidth_) (screenWidthSaver = screenWidth_)
#define SetPixel(x, y, color) ( *( (int*)(frameBuffer + (((y * screenWidthSaver) + x) * 4)) ) = (int)color )

extern int screenHeightSaver;
#define SaveScreenHeightForSafeSetPixel(screenHeight_) (screenHeightSaver = screenHeight_)
#define SafeSetPixel(x, y, color) (x >= 0 ? (x < screenWidthSaver ? (y >= 0 ? (y < screenHeightSaver ? (SetPixel(x, y, color)) : NULL) : NULL) : NULL) : NULL)

#endif

