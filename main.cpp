#define SHOW_CONSOLE
#include <graphics.h>
#include <iostream>
using namespace std;

#define WIDTH 1024
#define HEIGHT 576

void ShowPtrAddr(void* ptr){
	cout << (unsigned long long) ptr << endl;
}

void setup(PIMAGE image){
	setfillcolor(RED);
	bar(10, 10, 100, 100);
}

void loop (PIMAGE image){
	;
}

int main() {

	initgraph(WIDTH, HEIGHT, INIT_RENDERMANUAL);
	
	int frontBuffer = 0;

	for( ; is_run(); delay_fps(2) ) {
		setvisualpage(frontBuffer);
		setactivepage(!frontBuffer);
		frontBuffer = !frontBuffer;
		cout<<frontBuffer<<endl;
		if(frontBuffer == 0){
			setup(gettarget());
		}
	}

	closegraph();

}

