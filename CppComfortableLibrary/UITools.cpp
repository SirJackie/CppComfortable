#include "UITools.h"

void DrawBresenhamLine(int x0, int y0, int x1, int y1, int color){
	// Crucial 1 : 45 - 90 deg support
	// Crucial 2 : the 3rd quadrant support
	// Crucial 3 : the 2nd and 4th quadrant support
	
	// -----------------------------------------------
	
	// Crucial 1
	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if(steep){
		swap(&x0, &y0);
		swap(&x1, &y1);
	}
	
	// Crucial 2
	if(x0 > x1){
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	
	int dx = x1 - x0;
	int dy = abs(y1 - y0);  // Crucial 3
	int y = y0;
	int p = 2 * dy - dx;
	
	int stepY = y0 > y1 ? -1 : 1;  // Crucial 3
	
	for(int x = x0; x < x1; x++){
		
		// Crucial 1
		if(steep){
			SetPixel(y, x, color);
		}
		else{
			SetPixel(x, y, color);
		}
		
		if(p < 0){
			p += 2 * dy;
		}
		else{
			p += 2 * dy - 2 * dx;
			y += stepY;  // Crucial 3
		}
	}
	
}

