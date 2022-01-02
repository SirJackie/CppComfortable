#include <graphics.h>

void DrawRect(int x0, int y0, int x1, int y1, int color, color_t* buffer, int width=getwidth()){
	for(int y = y0; y < y1; y++){
		for(int x = x0; x < x1; x++){
			buffer[y * width + x] = color;
		}
	}
}

int main()
{	
	initgraph(1024, 500);
	
	PIMAGE img = newimage(1024, 500);
	color_t* buffer = getbuffer(img);
	DrawRect(10, 10, 100, 100, RED, buffer);
	putimage(0, 0, img);
	
	getch();
	delimage(img);
	closegraph();
}
