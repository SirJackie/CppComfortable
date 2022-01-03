#include <graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640, 480);
	outtextxy(0, 0, "please press any key");
	
	int k;
	for (;;)
	{
		if ( kbhit() ){
			k = getch();
			cleardevice();
		}
	}
	
	closegraph();
}

