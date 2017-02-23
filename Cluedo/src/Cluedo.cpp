#include <iostream>

int theory(int a, int b, int c){
	return 2;
}
int main() {
	int a = 1, b = 1, c = 1;

	for(int i = 0; i <= 25; i++){
		switch (theory(a, b, c)){
		case 0:
			std::cout << "YES";
			break;
		case 1:
			a++;
			break;
		case 2:
			b++;
			break;
		case 3:
			c++;
			break;
		}
	}
	return 0;
}
