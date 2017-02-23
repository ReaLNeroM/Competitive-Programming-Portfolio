#include <iostream>
#include <windows.h>

int main() {
	Beep(1500, 200);
	Beep(1000, 1000);
	Sleep(100);

	for(int i = 0; i < 10; i++){
		Beep(3000 + i * 500, 250);
		Sleep(10000);
		Beep(500 + i * 500, 250);
		Sleep(10000);
	}

	Sleep(100);
	Beep(2000, 200);
	Beep(3000, 200);
	Beep(5000, 1000);
	return 0;
}
