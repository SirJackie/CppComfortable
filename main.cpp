//第一个画图程序
#include <graphics.h>

int main()
{
	initgraph(1024, 576);
	
	setcolor(WHITE);
	setfillcolor(RED);
	setbkcolor(GRAY);
	
	// Line
	line(0, 0, 1024, 576);
	
	// Circle
	circle(100, 100, 100);
	fillcircle(100, 100, 100);
	
	// Ellipse
	ellipse(300, 300, 90, 180, 200, 100);
	sector(300, 300, 90, 180, 200, 100);
	fillellipse(300, 300, 200, 100);
	
	// Rect
	rectangle(10, 10, 100, 100);
	bar(10, 10, 100, 100);
	
	getch();
	closegraph();
}

