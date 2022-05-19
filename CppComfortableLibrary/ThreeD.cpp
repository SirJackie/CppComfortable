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

void GetForwardVector(float* cam, float* optForwardVector_Float3Lst){
	float x = 0, y = 0, z = 1;

	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
	ZYRot(&y, &z, cam[4]);

	optForwardVector_Float3Lst[0] = x;
	optForwardVector_Float3Lst[1] = y;
	optForwardVector_Float3Lst[2] = z;
}

void GetRightVector(float* cam, float* optRightVector_Float3Lst){
	float x = 1, y = 0, z = 0;

	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
	ZYRot(&y, &z, cam[4]);

	optRightVector_Float3Lst[0] = x;
	optRightVector_Float3Lst[1] = y;
	optRightVector_Float3Lst[2] = z;
}

void GetUpVector(float* cam, float* optUpVector_Float3Lst){
	float x = 0, y = 1, z = 0;

	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
	ZYRot(&y, &z, cam[4]);

	optUpVector_Float3Lst[0] = x;
	optUpVector_Float3Lst[1] = y;
	optUpVector_Float3Lst[2] = z;
}

void GetWalkingForwardVector(float* cam, float* optForwardVector_Float3Lst){
	float x = 0, y = 0, z = 1;

//	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
//	ZYRot(&y, &z, cam[4]);

	optForwardVector_Float3Lst[0] = x;
	optForwardVector_Float3Lst[1] = y;
	optForwardVector_Float3Lst[2] = z;
}

void GetWalkingRightVector(float* cam, float* optRightVector_Float3Lst){
	float x = 1, y = 0, z = 0;

//	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
//	ZYRot(&y, &z, cam[4]);

	optRightVector_Float3Lst[0] = x;
	optRightVector_Float3Lst[1] = y;
	optRightVector_Float3Lst[2] = z;
}

void GetWalkingUpVector(float* cam, float* optUpVector_Float3Lst){
	float x = 0, y = 1, z = 0;

//	XYRot(&x, &y, cam[5]);
	XZRot(&x, &z, cam[3]);
//	ZYRot(&y, &z, cam[4]);

	optUpVector_Float3Lst[0] = x;
	optUpVector_Float3Lst[1] = y;
	optUpVector_Float3Lst[2] = z;
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
		XYRot(xBuf + i, yBuf + i,  cam[5]);
		XZRot(xBuf + i, zBuf + i, -cam[3]);
		ZYRot(zBuf + i, yBuf + i,  cam[4]);
	}
}

void KeyboardlizeCamera(float* cam, float moveSpeed, float rotateSpeed){
	float vec[3] = {0.0f, 0.0f, 0.0f};

	if(IsKeyPressed(CSK_W)){
		GetWalkingForwardVector(cam, vec);
		cam[0] += vec[0] * moveSpeed;
		cam[1] += vec[1] * moveSpeed;
		cam[2] += vec[2] * moveSpeed;
	}
	if(IsKeyPressed(CSK_S)){
		GetWalkingForwardVector(cam, vec);
		cam[0] -= vec[0] * moveSpeed;
		cam[1] -= vec[1] * moveSpeed;
		cam[2] -= vec[2] * moveSpeed;
	}
	if(IsKeyPressed(CSK_A)){
		GetWalkingRightVector(cam, vec);
		cam[0] -= vec[0] * moveSpeed;
		cam[1] -= vec[1] * moveSpeed;
		cam[2] -= vec[2] * moveSpeed;
	}
	if(IsKeyPressed(CSK_D)){
		GetWalkingRightVector(cam, vec);
		cam[0] += vec[0] * moveSpeed;
		cam[1] += vec[1] * moveSpeed;
		cam[2] += vec[2] * moveSpeed;
	}
	if(IsKeyPressed(CSK_Space)){
		GetWalkingUpVector(cam, vec);
		cam[0] += vec[0] * moveSpeed;
		cam[1] += vec[1] * moveSpeed;
		cam[2] += vec[2] * moveSpeed;
	}
	if(IsKeyPressed(CSK_Shift)){
		GetWalkingUpVector(cam, vec);
		cam[0] -= vec[0] * moveSpeed;
		cam[1] -= vec[1] * moveSpeed;
		cam[2] -= vec[2] * moveSpeed;
	}

	if(IsKeyPressed(CSK_I)){
		cam[4] += rotateSpeed;
	}
	if(IsKeyPressed(CSK_K)){
		cam[4] -= rotateSpeed;
	}
	if(IsKeyPressed(CSK_J)){
		cam[3] -= rotateSpeed;
	}
	if(IsKeyPressed(CSK_L)){
		cam[3] += rotateSpeed;
	}
	if(IsKeyPressed(CSK_U)){
		cam[5] -= rotateSpeed;
	}
	if(IsKeyPressed(CSK_O)){
		cam[5] += rotateSpeed;
	}
}

void MousilizeCamera(float* cam, float sensitivity){
	if(mouseState.lPressed){
		cam[3] += mouseState.deltaX * sensitivity;
		cam[4] -= mouseState.deltaY * sensitivity;
	}
}

void ShowCamera(float* cam){
	cout << "CamX: " << cam[0] << "; CamY: " << cam[1] << "; CamZ: " << cam[2]
		 << "; Rot3: " << cam[3] << "; Rot4: " << cam[4] << "; Rot5:" << cam[5] << endl;
}

ThreeDPipeline::ThreeDPipeline(int screenWidth_, int screenHeight_, float fovY_){
	screenWidth = screenWidth_;
	screenHeight = screenHeight_;
	fovY = fovY_;
}

void ThreeDPipeline::ShowDebugInfo(){
	cout << "ThreeDPipeline{" << endl
		 << "\tscreenWidth = " << screenWidth << endl
		 << "\tscreenHeight = " << screenHeight << endl
		 << "\tfovY = " << fovY << endl
		 << "}" << endl;
}

