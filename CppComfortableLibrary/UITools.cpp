#include "UITools.h"

void DrawBresenhamLine(int x0, int y0, int x1, int y1, int color){
	SetPixel(x0, y0, (int)color);
	SetPixel(x1, y1, (int)color);
}

