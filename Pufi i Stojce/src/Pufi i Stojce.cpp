#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << (3 - ((a + b + c) % 3)) % 3;
	/*
	zbir = a + b;
	zbir += c;

	for(int i = 0; i < 3; i++){
		if((zbir + i) % 3 == 0){
			std::cout << i;
			break;
		}
	}
*/
	return 0;
}
