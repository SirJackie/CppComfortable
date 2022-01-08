#include "./CppComfortableLibrary/UILifeCycle.h"
#include "./CppComfortableLibrary/ConsoleTools.h"
#include "./CppComfortableLibrary/FrameBufferTools.h"
#include "./CppComfortableLibrary/MathTools.h"
#include "./CppComfortableLibrary/ThreeD.h"

#define WIDTH 1024
#define HEIGHT 576

//void setup() {
//	;
//}
//
//float xBuf[4] = {-1.77777f, 1.77777f, -1.77777f, 1.77777f};
//float yBuf[4] = {1.0f, 1.0f, -1.0f, -1.0f};
//float zBuf[4] = {1.0f, 2.0f, 1.0f, 2.0f};
//
//float tXBuf[4], tYBuf[4], tZBuf[4];
//
//void loop() {
//	int bufLen = sizeof(xBuf) / sizeof(float);
//
//	BatchCopyBuf(xBuf, yBuf, zBuf, tXBuf, tYBuf, tZBuf, bufLen);
//	BatchProject(tXBuf, tYBuf, tZBuf, bufLen);
//	BatchExpand(tXBuf, tYBuf, bufLen, 120.0f);
//	BatchPubelize(tXBuf, tYBuf, bufLen, WIDTH, HEIGHT);
//	BatchShowBuf(tXBuf, tYBuf, tZBuf, bufLen);
//	BatchDrawBuf(tXBuf, tYBuf, bufLen, WIDTH, HEIGHT);
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
//	DeconstructWindow();
//}

int main(){
	ConstructWindow(WIDTH, HEIGHT);
	
	PreSetup();
	PostSetup();
	
	for LifeCycle {
		PreLoop();
		
		int kbmsgResult = kbmsg();
		
		key_msg getkeyResult = {0};
		if(kbmsgResult){
			getkeyResult = getkey();
		}
		else{
			getkeyResult = {0};
		}
		
		cout << kbmsgResult << ", " << getkeyResult.key << endl;
		
		PostLoop();
	}
	
	DeconstructWindow();
}

