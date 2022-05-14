#include "UITools.h"

void DrawBresenhamLine(int x0, int y0, int x1, int y1, int color){
	
	// Crucial Point: 45 - 90 deg adapter
	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if(steep){
		swap(&x1, &y1);
		swap(&x0, &y0);
	}
	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int y = y0;
	int pk = 2 * dy - dx;  // Init value of decision parameter
	
	for(int x = x0; x < x1; x++){
		if(steep){
			SetPixel(y, x, color);
		}
		else{
			SetPixel(x, y, color);
		}
		
		if(pk < 0){        // When pk < 0
			pk += 2 * dy;  // pk+1 = pk + 2dy
			;              // yk+1 = yk
		}
		else{                       // When pk >= 0
			pk += 2 * dy - 2 * dx;  // pk+1 = pk + 2dy - 2dx;
			y += 1;                 // yk+1 = yk + 1
		}
	}
	
}

