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

float xBuf[8] = {-1, 1, 1, -1, -1, 1, 1, -1};
float yBuf[8] = {1, 1, -1, -1, 1, 1, -1, -1};
float zBuf[8] = {-1, -1, -1, -1, 1, 1, 1, 1};

float tXBuf[8], tYBuf[8], tZBuf[8];

float cam[6] = {-0.0f, 0.0f, -5.0f, 0.0f, 0.0f, 0.0f};

void setup() {
	tdpp.ShowDebugInfo();
	tdpp.AttachVertexBuffer(sizeof(xBuf) / sizeof(float), xBuf, yBuf, zBuf);
	tdpp.AttachTempBuffer(tXBuf, tYBuf, tZBuf);
	tdpp.AttachCamera(cam);
}

void loop() {

	// Mouse Processing
	// ShowMouseState();

	// 3D Graphics Rendering
	int bufLen = sizeof(xBuf) / sizeof(float);

	BatchCopyBuf(xBuf, yBuf, zBuf, tXBuf, tYBuf, tZBuf, bufLen);

	KeyboardlizeCamera(cam, 0.05f, 1.0f);
	MousilizeCamera(cam, 0.1f);
	
	tdpp.ApplyVertexTransformation();

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

