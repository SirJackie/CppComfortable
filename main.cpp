#include <graphics.h>

int main()
{
	initgraph(1024, 576);

	//�Ȼ�һ�����Σ��Ա��ڿ�������ɫ������
	setfillcolor(EGERGB(0x0, 0x80, 0x80));
	bar(10, 10, 1014, 566);
	
	//������ɫ
	setcolor(EGERGB(0x0, 0xFF, 0x0));
	
	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	
	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
	setfont(40, 0, "����");
	
	//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
	//Ҫʹ�������ʽ���ַ�����outtextrect
	outtextxy(30, 30, "Hello EGE ����֧��");
	outtextrect(30, 80, 200, 100, "Hello EGE\n����֧��");
	
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	setbkcolor(RED);
	outtextxy(30, 170, "͸����������");

	getch();
	closegraph();
}

