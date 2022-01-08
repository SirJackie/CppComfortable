#ifndef __CppComfortable_ThreeD_H__
#define __CppComfortable_ThreeD_H__

#include "MathTools.h"
#include "FrameBufferTools.h"
#include "ConsoleTools.h"

// ar for Aspect Ratio
// sw for Screen Width
// sh for Screen Height

float FPubeX(float x, float ar, float sw);
float FPubeY(float y, float sh);
float FExpandX(float x, float fovY);
float FExpandY(float y, float fovY);

void BatchCopyBuf(float* xBuf, float* yBuf, float* newXBuf, float* newYBuf, int length);
void BatchShowBuf(float* xBuf, float* yBuf, int length);
void BatchDrawBuf(float* xBuf, float* yBuf, int length, int screenWidth, int screenHeight);

void BatchPubelize(float* xbuf, float* ybuf, int length, float sw, float sh);
void BatchExpand(float* xbuf, float* ybuf, int length, float fovY);

#endif

