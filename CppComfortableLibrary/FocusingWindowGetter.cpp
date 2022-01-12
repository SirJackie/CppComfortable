#include "FocusingWindowGetter.h"

bool IsEGEWindowFocused(){
	HWND activeWindow = GetForegroundWindow();
	HWND egeWindow = getHWnd();
	
	if(activeWindow == egeWindow){
		return true;
	}
	else{
		return false;
	}
}

