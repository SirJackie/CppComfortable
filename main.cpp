//ʹ��IMAGE����ץͼ���滭��IMAGE��IMAGE����Ļ
#include <graphics.h>

//IMAGE�����൱��һ����ͼ�壬��ͬʱҲ������ΪͼƬ��������IMAGE��
//����һ���ǳ����Ķ��󣬸��ӵĻ�ͼ��Ҫ����IMAGE���Ա���õر�������ͼ��

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
	
//	putimage(0, 0, img);
//	putimage(80, 0, img);
	
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			//��img���������컭��ָ���ľ�����
			//��Ҫָ��Ŀ����Σ�Դ����
			//Դ���β������ܺ��ԣ����������������칦�ܵ���ͼ��������
			putimage(x * 160, y * 120, 160, 120, img, 0, 0, 80, 60);
		}
	}
	
	delimage(img);
	
	getch();
	closegraph();
}
