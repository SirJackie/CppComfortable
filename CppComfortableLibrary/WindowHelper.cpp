#include "WindowHelper.h"

HWND GetEGEWindowHandler(){
	return getHWnd();
}

bool IsEGEWindowFocused(){
	HWND activeWindow = GetForegroundWindow();
	HWND egeWindow = GetEGEWindowHandler();

	if(activeWindow == egeWindow){
		return true;
	}
	else{
		return false;
	}
}

void HideTitleBar(){
	HWND egeWindow = GetEGEWindowHandler();
	LONG wndStyle = GetWindowLong(egeWindow, GWL_STYLE);
	wndStyle &= ~(WS_CAPTION);
	SetWindowLong(egeWindow, GWL_STYLE, wndStyle);
}

