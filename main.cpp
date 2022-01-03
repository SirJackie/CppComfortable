#include <graphics.h>
#include <math.h>

#define SCR_WIDTH      800
#define SCR_HEIGHT     600

struct Ball {
	float x,y;
	float dx,dy;
	float radius;
	color_t color;
};

int main() {
	initgraph(SCR_WIDTH, SCR_HEIGHT, INIT_RENDERMANUAL);
	Ball ball[500];
	float dir = 0.0f;
	float sp = 0.5f;
	
	for(int i = 0; i != 500; ++i){
		ball[i].x = SCR_WIDTH / 2;
		ball[i].y = SCR_HEIGHT / 2;
		randomize();
		sp += 0.01f;
		ball[i].dx = sp * cosf(dir);
		ball[i].dy = sp * sinf(dir);
		ball[i].radius = randomf() * 5 + 2;
		ball[i].color = random(0xff0000) + 0xffff;
		dir += 0.1f;
	}
	
	int n = 1;
	double t = fclock();
	for(; is_run(); delay_fps(60)) {
		cleardevice();
		if (kbhit()) {
			if (getch() == 27)
				break;
			n += 63;
			n %= 500;
		}
		if(fclock() - t > 0.2) {
			t = fclock();
			if (n < 500) ++n;
		}
		for(int i = 0; i != n; ++i) {
			setfillcolor(ball[i].color);
			setcolor(ball[i].color);
			fillellipse(ball[i].x,ball[i].y,ball[i].radius,ball[i].radius);
			ball[i].x += ball[i].dx;
			ball[i].y += ball[i].dy;
			if(ball[i].x < 0.0f || ball[i].x > SCR_WIDTH) ball[i].dx = -ball[i].dx;
			if(ball[i].y < 0.0f || ball[i].y > SCR_HEIGHT) ball[i].dy = -ball[i].dy;
		}
	}
	closegraph();
	return 0;
}

