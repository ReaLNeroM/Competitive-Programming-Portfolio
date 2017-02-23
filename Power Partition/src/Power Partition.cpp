#include <iostream>

typedef long long ll;

int main() {
	long long base, num;
	std::cin >> base >> num;

	int power = -1;
	for(int i = 1; i <= num; i *= base){
		power++;
	}

	long long ways[power];

	return 0;
}
