#include <iostream>
#include <cmath>

int main() {
	int vertices;
	std::cin >> vertices;

	int x[vertices], y[vertices];
	for(int i = 0; i < vertices; i++){
		std::cin >> x[i] >> y[i];
	}

	int ways = 0;
	for(int i = 0; i < vertices; i++){
		for(int j = i + 1; j < vertices; j++){
			for(int k = j + 1; k < vertices; k++){
				if((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - (x[j] * y[i] + x[k] * y[j] + x[i] * y[k])){
					ways++;
				}
			}
		}
	}

	std::cout << ways;
	return 0;
}
