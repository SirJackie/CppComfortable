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

void ShowCamera(float* cam){
	cout << "CamX: " << cam[0] << "; CamY: " << cam[1] << "; CamZ: " << cam[2]
		 << "; Rot3: " << cam[3] << "; Rot4: " << cam[4] << "; Rot5:" << cam[5] << endl;
}

//void DrawTriangle(const FVectorTex& v0_, const FVectorTex& v1_, const FVectorTex& v2_, CS_FrameBuffer& texture){
//	// Sort Y Order
//	FVectorTex *v0ptr = (FVectorTex*)&v0_;
//	FVectorTex *v1ptr = (FVectorTex*)&v1_;
//	FVectorTex *v2ptr = (FVectorTex*)&v2_;
//	if(v0ptr->pos.y > v1ptr->pos.y) swap(v0ptr, v1ptr);
//	if(v0ptr->pos.y > v2ptr->pos.y) swap(v0ptr, v2ptr);
//	if(v1ptr->pos.y > v2ptr->pos.y) swap(v1ptr, v2ptr);
//	
//	// Natural Flat Triangle
//	if(v1ptr->pos.y == v2ptr->pos.y){
//		// ptrfb->PrintLn("Flat Bottom Triangle");
//		if(v1ptr->pos.x > v2ptr->pos.x) swap(v1ptr, v2ptr);
//		DrawFlatBottomTriangle(
//			*v0ptr, *v1ptr, *v2ptr,
//			texture
//			);
//		return;
//	}
//	
//	if(v0ptr->pos.y == v1ptr->pos.y){
//		// ptrfb->PrintLn("Flat Top Triangle");
//		if(v0ptr->pos.x > v1ptr->pos.x) swap(v0ptr, v1ptr);
//		DrawFlatTopTriangle(
//			*v0ptr, *v1ptr, *v2ptr,
//			texture
//			);
//		return;
//	}
//	
//	// Normal Triangle
//	FVectorTex v0 = *v0ptr;
//	FVectorTex v1 = *v1ptr;
//	FVectorTex v2 = *v2ptr;
//	
//	f32 m = v1.pos.y - v0.pos.y;
//	f32 n = v2.pos.y - v0.pos.y;
//	FVectorTex vcenter = v0.InterpolateTo(v2, m / n);
//	
//	if(vcenter.pos.x < v1.pos.x){
//		// ptrfb->PrintLn("Longside Left Triangle");
//		DrawFlatBottomTriangle(
//			v0, vcenter, v1,
//			texture
//			);
//		DrawFlatTopTriangle(
//			vcenter, v1, v2,
//			texture
//			);
//	}
//	
//	else{
//		// ptrfb->PrintLn("Longside Right Triangle");
//		DrawFlatBottomTriangle(
//			v0, v1, vcenter,
//			texture
//			);
//		DrawFlatTopTriangle(
//			v1, vcenter, v2,
//			texture
//			);
//	}
//	
//}
//
//void DrawFlatBottomTriangle(const FVectorTex& v0_, const FVectorTex& v1_, const FVectorTex& v2_, CS_FrameBuffer& texture){
//	const f32& yTop    = v0_.pos.y;
//	const f32& yBottom = v2_.pos.y;
//	
//	FVectorTex xLeftStep  = (v1_ - v0_) / (yBottom - yTop);
//	FVectorTex xRightStep = (v2_ - v0_) / (yBottom - yTop);
//	
//	DrawFlatTriangle(
//		ceil(yTop - 0.5f),
//		ceil(yBottom - 0.5f),
//		v0_ + (ceil(yTop - 0.5f) + 0.5f - yTop) * xLeftStep,   // xLeft  with Pre-stepping
//		v0_ + (ceil(yTop - 0.5f) + 0.5f - yTop) * xRightStep,  // xRight with Pre-stepping
//		xLeftStep,
//		xRightStep,
//		texture
//		);
//}
//
//void DrawFlatTopTriangle(const FVectorTex& v0_, const FVectorTex& v1_, const FVectorTex& v2_, CS_FrameBuffer& texture){
//	const f32& yTop    = v0_.pos.y;
//	const f32& yBottom = v2_.pos.y;
//	
//	FVectorTex xLeftStep  = (v2_ - v0_) / (yBottom - yTop);
//	FVectorTex xRightStep = (v2_ - v1_) / (yBottom - yTop);
//	
//	DrawFlatTriangle(
//		ceil(yTop - 0.5f),
//		ceil(yBottom - 0.5f),
//		v0_ + (ceil(yTop - 0.5f) + 0.5f - yTop) * xLeftStep,   // xLeft  with Pre-stepping
//		v1_ + (ceil(yTop - 0.5f) + 0.5f - yTop) * xRightStep,  // xRight with Pre-stepping
//		xLeftStep,
//		xRightStep,
//		texture
//		);
//}
//
//void DrawFlatTriangle(i32 yTop, i32 yBottom, FVectorTex xLeft, FVectorTex xRight, const FVectorTex& xLeftStep, const FVectorTex& xRightStep, CS_FrameBuffer& texture)
//{
//	for (i32 y = yTop; y < yBottom; y++) {
//		
//		i32 xLeftInt  = ceil(xLeft.pos.x  - 0.5f);
//		i32 xRightInt = ceil(xRight.pos.x - 0.5f);
//		
//		FVectorTex xNowStep = (xRight - xLeft) / (xRight.pos.x - xLeft.pos.x);
//		FVectorTex xNow = xLeft;
//		xNow = xNow + ((float)xLeftInt + 0.5f - xLeft.pos.x) * xNowStep;  // Pre-stepping
//		
//		for (i32 x = xLeftInt; x < xRightInt; x++) {
//			f32& zbPos = zb.bufptr[((i32)xNow.pos.y * zb.width + (i32)xNow.pos.x)];
//			
//			if(zbPos < xNow.pos.z){
//				i32 position = CS_iclamp(0, xNow.tex.y * texture.width,  texture.height - 1) *
//				texture.width +
//				CS_iclamp(0, xNow.tex.x * texture.height, texture.width  - 1);
//				
//				CS_PutPixel(
//					*ptrfb, xNow.pos.x, xNow.pos.y,
//					texture.redBuffer   [position],
//					texture.greenBuffer [position],
//					texture.blueBuffer  [position]
//					);
//				zbPos = xNow.pos.z;
//			}
//			
//			xNow += xNowStep;
//		}
//		
//		xLeft += xLeftStep;
//		xRight += xRightStep;
//	}
//}

