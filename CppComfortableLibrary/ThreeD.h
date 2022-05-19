#ifndef __CppComfortable_ThreeD_H__
#define __CppComfortable_ThreeD_H__

#include "MathTools.h"
#include "FrameBufferTools.h"
#include "ConsoleTools.h"
#include "QuickKeyBoard.h"
#include "QuickMouse.h"
#include "ConsoleTools.h"

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

void GetForwardVector(float* cam, float* optForwardVector_Float3Lst);
void GetRightVector(float* cam, float* optRightVector_Float3Lst);
void GetUpVector(float* cam, float* optUpVector_Float3Lst);

void GetWalkingForwardVector(float* cam, float* optForwardVector_Float3Lst);
void GetWalkingRightVector(float* cam, float* optRightVector_Float3Lst);
void GetWalkingUpVector(float* cam, float* optUpVector_Float3Lst);

void BatchCopyBuf(float* xBuf, float* yBuf, float* zBuf, float* newXBuf, float* newYBuf, float* newZBuf, int length);
void BatchShowBuf(float* xBuf, float* yBuf, float* zBuf, int length);
void BatchDrawBuf(float* xBuf, float* yBuf, float* zBuf, int length, int screenWidth, int screenHeight);

void BatchPubelize(float* xBuf, float* yBuf, int length, float sw, float sh);
void BatchExpand(float* xBuf, float* yBuf, int length, float fovY);
void BatchProject(float* xBuf, float* yBuf, float* zBuf, int length);
void BatchTranslate(float* xBuf, float* yBuf, float* zBuf, float* cam, int length);
void BatchRotation(float* xBuf, float* yBuf, float* zBuf, float* cam, int length);

void KeyboardlizeCamera(float* cam, float moveSpeed, float rotateSpeed);
void MousilizeCamera(float* cam, float sensitivity);
void ShowCamera(float* cam);

class ThreeDPipeline{
public:
	int screenWidth;
	int screenHeight;
	float fovY;

private:
	int vertexBufferLength;
	float* xBuf;
	float* yBuf;
	float* zBuf;
	float* txBuf;
	float* tyBuf;
	float* tzBuf;
	float* cam;

public:
	ThreeDPipeline(int screenWidth_, int screenHeight_, float fovY_);
	void ShowDebugInfo();
	void AttachVertexBuffer(int length_, float* xBuf_, float* yBuf_, float* zBuf_);
	void AttachTempBuffer(float* txBuf_, float* tyBuf_, float* tzBuf_);
	void AttachCamera(float* cam_);
	void ApplyVertexTransformation();
};

#endif

