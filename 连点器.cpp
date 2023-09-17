#include<iostream>
#include<conio.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
int main(){
	char x;
	int n;
	printf("按A点击左键\n");
	printf("按D点击右键\n");
	printf("按S停止点击\n");
	while(1){
		if(KEY_DOWN('S')){
			n=0;
			Sleep(0);
		}
		if(KEY_DOWN('A')){
			n=1;
			Sleep(0);
		}
 		if(KEY_DOWN('D')){
			n=2;
			Sleep(0);
		}
		if(n==1){
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		}
		if(n==2){
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
			Sleep(0);
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		}
		Sleep(0);
	}
}
