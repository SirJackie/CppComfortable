#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"
#include "./CppComfortableLibrary/QuickKeyBoard.h"

#define WIDTH 1024
#define HEIGHT 576

//void setup() {
//	;
//}
//
//float xBuf[8] = {-1, 1, 1, -1, -1, 1, 1, -1};
//float yBuf[8] = {1, 1, -1, -1, 1, 1, -1, -1};
//float zBuf[8] = {-1, -1, -1, -1, 1, 1, 1, 1};
//
//float tXBuf[8], tYBuf[8], tZBuf[8];
//
//float cam[6] = {-0.0f, 0.0f, -5.0f, 0.0f, 0.0f, 0.0f};
//
//void loop() {
//	int bufLen = sizeof(xBuf) / sizeof(float);
//
//	BatchCopyBuf(xBuf, yBuf, zBuf, tXBuf, tYBuf, tZBuf, bufLen);
//
//	KeyboardlizeCamera(cam, 0.05f, 1.0f);
//	ShowCamera(cam);
//
//	BatchTranslate(tXBuf, tYBuf, tZBuf, cam, bufLen);
//	BatchRotation(tXBuf, tYBuf, tZBuf, cam, bufLen);
//	BatchProject(tXBuf, tYBuf, tZBuf, bufLen);
//	BatchExpand(tXBuf, tYBuf, bufLen, 60.0f);
//	BatchPubelize(tXBuf, tYBuf, bufLen, WIDTH, HEIGHT);
//
////	BatchShowBuf(tXBuf, tYBuf, tZBuf, bufLen);
//	BatchDrawBuf(tXBuf, tYBuf, tZBuf, bufLen, WIDTH, HEIGHT);
//}
//
//int main() {
//	ConstructWindow(WIDTH, HEIGHT);
//
//	PreSetup();
//	setup();
//	PostSetup();
//
//	for LifeCycle {
//		PreLoop();
//		loop();
//		PostLoop();
//	}
//
//	DestructWindow();
//}

struct MouseState{
	int x;
	int y;
	bool lPressed;
	bool mPressed;
	bool rPressed;
};

MouseState mouseState = {0};

void ShowMouseState(){
	cout << "MouseX: " << mouseState.x << "; MouseY: " << mouseState.y << "; LMR: " << mouseState.lPressed << mouseState.mPressed << mouseState.rPressed << endl;
}

int count = 10;

int main(){
	ConstructWindow(WIDTH, HEIGHT);

	PreSetup();
	PostSetup();

	for LifeCycle {
		PreLoop();

		mousepos(&(mouseState.x), &(mouseState.y));
		mouseState.lPressed = IsKeyPressed(CSK_LButton);
		mouseState.rPressed = IsKeyPressed(CSK_RButton);
		ShowMouseState();

		PostLoop();
	}

	DestructWindow();
}

