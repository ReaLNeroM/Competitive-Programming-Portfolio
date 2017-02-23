#include <iostream>

void print(int n, int curr = 1){
	if(curr >= n){
		return;
	}
	std::cout << n;
	print(n, curr + 1);
}

void d(int n, int curr = 1){
	if(curr > n){
		return;
	}

	print(curr);
	std::cout << std::endl;
	d(n, curr + 1);
}

int main() {
	d(14);
}
