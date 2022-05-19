#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"
#include "./CppComfortableLibrary/QuickKeyBoard.h"
#include "./CppComfortableLibrary/QuickMouse.h"
#include "./CppComfortableLibrary/WindowHelper.h"
#include "./CppComfortableLibrary/UITools.h"

#define WIDTH 1024
#define HEIGHT 576

ThreeDPipeline tdpp = ThreeDPipeline(WIDTH, HEIGHT, 60.0f);

void setup() {
	tdpp.ShowDebugInfo();
}

float xBuf[8] = {-1, 1, 1, -1, -1, 1, 1, -1};
float yBuf[8] = {1, 1, -1, -1, 1, 1, -1, -1};
float zBuf[8] = {-1, -1, -1, -1, 1, 1, 1, 1};

float tXBuf[8], tYBuf[8], tZBuf[8];

float cam[6] = {-0.0f, 0.0f, -5.0f, 0.0f, 0.0f, 0.0f};

void loop() {

	// Mouse Processing
	// ShowMouseState();

	// 3D Graphics Rendering
	int bufLen = sizeof(xBuf) / sizeof(float);

	BatchCopyBuf(xBuf, yBuf, zBuf, tXBuf, tYBuf, tZBuf, bufLen);

	KeyboardlizeCamera(cam, 0.05f, 1.0f);
	MousilizeCamera(cam, 0.1f);
	// ShowCamera(cam);

	BatchTranslate(tXBuf, tYBuf, tZBuf, cam, bufLen);
	BatchRotation(tXBuf, tYBuf, tZBuf, cam, bufLen);
	BatchProject(tXBuf, tYBuf, tZBuf, bufLen);
	BatchExpand(tXBuf, tYBuf, bufLen, 60.0f);
	BatchPubelize(tXBuf, tYBuf, bufLen, WIDTH, HEIGHT);

	BatchDrawBuf(tXBuf, tYBuf, tZBuf, bufLen, WIDTH, HEIGHT);
}

int main() {
	ConstructWindow(WIDTH, HEIGHT);
	HideTitleBar();

	PreSetup();
	setup();
	PostSetup();

	for LifeCycle {
		UpdateMouseState();
		PreLoop();
		loop();
		PostLoop();
	}

	DestructWindow();
}

