#include <iostream>

typedef long long ll;

int euclid(int a, int b){
	if(b == 0){
		return a;
	}

	return euclid(b, a % b);
}
int main() {
	int a, b;
	std::cin >> a >> b;

	std::cout << euclid(a, b);
	return 0;
}
