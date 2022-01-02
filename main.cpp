#include <graphics.h>

int main()
{
	initgraph(1024, 576);

	//先画一个矩形，以便于看出背景色的问题
	setfillcolor(EGERGB(0x0, 0x80, 0x80));
	bar(10, 10, 1014, 566);
	
	//文字颜色
	setcolor(EGERGB(0x0, 0xFF, 0x0));
	
	//文字背景色（注意setbkcolor函数也会同时改变文字背景色）
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	
	//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
	//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
	setfont(40, 0, "宋体");
	
	//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
	//要使用特殊格式化字符请用outtextrect
	outtextxy(30, 30, "Hello EGE 中文支持");
	outtextrect(30, 80, 200, 100, "Hello EGE\n中文支持");
	
	//设置文字背景填充方式为透明，默认为OPAQUE不透明
	setbkmode(TRANSPARENT);
	setbkcolor(RED);
	outtextxy(30, 170, "透明背景文字");

	getch();
	closegraph();
}

