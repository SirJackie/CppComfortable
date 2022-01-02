//使用IMAGE——抓图，绘画到IMAGE，IMAGE到屏幕
#include <graphics.h>

//IMAGE对象相当于一个绘图板，而同时也可以作为图片画到其它IMAGE上
//它是一个非常灵活的对象，复杂的绘图都要借助IMAGE，以便更好地保存和输出图像

int main()
{
	initgraph(640, 480);
	
	setcolor(EGERGB(255, 255, 255));
	setfillcolor(EGERGB(255, 0, 0));
	
	fillcircle(100, 100, 100);
	
	PIMAGE img = newimage();
	getimage(img, 0, 0, 80, 60);
	
	setfillcolor(BLACK);
	bar(0, 0, getwidth(), getheight());
	
	setfillcolor(RED, img);
	bar(10, 10, 20, 20, img);
	putimage(0, 0, img);
	putimage(80, 0, img);
	
	delimage(img);
	
	getch();
	closegraph();
}
