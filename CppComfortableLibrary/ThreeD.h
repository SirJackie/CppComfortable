#ifndef __CppComfortable_ThreeD_H__
#define __CppComfortable_ThreeD_H__

#include "MathTools.h"
#include "FrameBufferTools.h"
#include "ConsoleTools.h"
#include "QuickKeyBoard.h"

// ar for Aspect Ratio
// sw for Screen Width
// sh for Screen Height

float FPubeX(float x, float ar, float sw);
float FPubeY(float y, float sh);
float FExpandX(float x, float fovY);
float FExpandY(float y, float fovY);

void XYRot(float* x, float* y, float alpha);
void XZRot(float* x, float* z, float alpha);
void ZYRot(float* z, float* y, float alpha);

void BatchCopyBuf(float* xBuf, float* yBuf, float* zBuf, float* newXBuf, float* newYBuf, float* newZBuf, int length);
void BatchShowBuf(float* xBuf, float* yBuf, float* zBuf, int length);
void BatchDrawBuf(float* xBuf, float* yBuf, float* zBuf, int length, int screenWidth, int screenHeight);

void BatchPubelize(float* xBuf, float* yBuf, int length, float sw, float sh);
void BatchExpand(float* xBuf, float* yBuf, int length, float fovY);
void BatchProject(float* xBuf, float* yBuf, float* zBuf, int length);
void BatchTranslate(float* xBuf, float* yBuf, float* zBuf, float* cam, int length);
void BatchRotation(float* xBuf, float* yBuf, float* zBuf, float* cam, int length);

void KeyboardlizeCamera(float* cam, float moveSpeed, float rotateSpeed);
void ShowCamera(float* cam);

#endif

