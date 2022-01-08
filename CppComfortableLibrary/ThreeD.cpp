#include "ThreeD.h"

float FPubeX(float x, float ar, float sw){
	return ((x + ar) / (2.0f * ar)) * sw;
}

float FPubeY(float y, float sh){
	return ((1-y) / 2.0f) * sh;
}

float FExpandX(float x, float fovY){
	return x * (1.0f / tand(fovY / 2.0f));
}

float FExpandY(float y, float fovY){
	return y * (1.0f / tand(fovY / 2.0f));
}

void BatchCopyBuf(float* xBuf, float* yBuf, float* zBuf, float* newXBuf, float* newYBuf, float* newZBuf, int length){
	for(int i = 0; i < length; i++){
		newXBuf[i] = xBuf[i];
		newYBuf[i] = yBuf[i];
		newZBuf[i] = zBuf[i];
	}
}

void BatchShowBuf(float* xBuf, float* yBuf, float* zBuf, int length){
	cout << "----------------------------------------" << endl;
	for(int i = 0; i < length; i++){
		cout << "X: " << xBuf[i] << "; Y: " << yBuf[i] << endl;
	}
	cout << "----------------------------------------" << endl;
}

void BatchDrawBuf(float* xBuf, float* yBuf, int length, int screenWidth, int screenHeight){
	for(int i = 0; i < length; i++){
		DrawPoint(xBuf[i], yBuf[i], 5, 255, 255, 255, screenWidth, screenHeight);
	}
}

void BatchPubelize(float* xBuf, float* yBuf, int length, float sw, float sh){
	float ar = sw / sh;
	for(int i = 0; i < length; i++){
		xBuf[i] = FPubeX(xBuf[i], ar, sw);
		yBuf[i] = FPubeY(yBuf[i], sh);
	}
}

void BatchExpand(float* xBuf, float* yBuf, int length, float fovY){
	for(int i = 0; i < length; i++){
		xBuf[i] = FExpandX(xBuf[i], fovY);
		yBuf[i] = FExpandY(yBuf[i], fovY);
	}
}

void BatchProject(float* xBuf, float* yBuf, float* zBuf, int length){
	for(int i = 0; i < length; i++){
		xBuf[i] = xBuf[i] / zBuf[i];
		yBuf[i] = yBuf[i] / zBuf[i];
	}
}

