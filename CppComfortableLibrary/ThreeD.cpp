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

void XYRot(float* x, float* y, float alpha){
	float ox = *x, oy = *y;
	*x = cosd(alpha) * ox + sind(alpha) * oy;
	*y = cosd(alpha) * oy - sind(alpha) * ox;
}

void XZRot(float* x, float* z, float alpha){
	float ox = *x, oz = *z;
	*x = cosd(alpha) * ox + sind(alpha) * oz;
	*z = cosd(alpha) * oz - sind(alpha) * ox;
}

void ZYRot(float* z, float* y, float alpha){
	float oz = *z, oy = *y;
	*z = cosd(alpha) * oz + sind(alpha) * oy;
	*y = cosd(alpha) * oy - sind(alpha) * oz;
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
		cout << "X: " << xBuf[i] << "; Y: " << yBuf[i] << "; Z: " << zBuf[i] << endl;
	}
	cout << "----------------------------------------" << endl;
}

void BatchDrawBuf(float* xBuf, float* yBuf, float* zBuf, int length, int screenWidth, int screenHeight){
	for(int i = 0; i < length; i++){
		DrawPoint(xBuf[i], yBuf[i], 10 - zBuf[i], 255, 255, 255, screenWidth, screenHeight);
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

void BatchTranslate(float* xBuf, float* yBuf, float* zBuf, float* cam, int length){
	for(int i = 0; i < length; i++){
		xBuf[i] -= cam[0];
		yBuf[i] -= cam[1];
		zBuf[i] -= cam[2];
	}
}

void BatchRotation(float* xBuf, float* yBuf, float* zBuf, float* cam, int length){
	for(int i = 0; i < length; i++){
		XYRot(xBuf + i, yBuf + i, cam[3]);
	}
}

void KeyboardlizeCamera(float* cam, float speed){
	if(IsKeyPressed(CSK_W)){
		cam[2] += speed;
	}
	if(IsKeyPressed(CSK_S)){
		cam[2] -= speed;
	}
	if(IsKeyPressed(CSK_A)){
		cam[0] -= speed;
	}
	if(IsKeyPressed(CSK_D)){
		cam[0] += speed;
	}
	if(IsKeyPressed(CSK_Space)){
		cam[1] += speed;
	}
	if(IsKeyPressed(CSK_Shift)){
		cam[1] -= speed;
	}
}

void ShowCamera(float* cam){
	cout << "CamX: " << cam[0] << "; CamY: " << cam[1] << "; CamZ: " << cam[2] 
		 << "; XYRot: " << cam[3] << "; XZRot: " << cam[4] << "; ZYRot:" << cam[5] << endl;
}

