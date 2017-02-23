#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int vertex[n];
	char edge[n - 1];
	for(int i = 0; i < n - 1; i++){
		std::cin >> vertex[i] >> edge[i];
	}
	std::cin >> vertex[n - 1];


	return 0;
}
