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

void BatchCopyBuf(float* xBuf, float* yBuf, float* newXBuf, float* newYBuf, int length){
	for(int i = 0; i < length; i++){
		newXBuf[i] = xBuf[i];
		newYBuf[i] = yBuf[i];
	}
}

void BatchShowBuf(float* xBuf, float* yBuf, int length){
	cout << "----------------------------------------" << endl;
	for(int i = 0; i < length; i++){
		cout << "X: " << xBuf[i] << "; Y: " << yBuf[i] << endl;
	}
	cout << "----------------------------------------" << endl;
}

void BatchPubelize(float* xbuf, float* ybuf, int length, float sw, float sh){
	float ar = sw / sh;
	for(int i = 0; i < length; i++){
		xbuf[i] = FPubeX(xbuf[i], ar, sw);
		ybuf[i] = FPubeY(ybuf[i], sh);
	}
}

