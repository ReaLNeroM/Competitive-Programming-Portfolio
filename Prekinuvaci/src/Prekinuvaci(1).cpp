#include <iostream>
#include <cmath>

int main() {
	int n;
	std::cin >> n;

	int control[n];
	bool on[n];
	for(int i = 0, inp; i < n; i++){
		std::cin >> inp;
		control[inp - 1] = i;

		on[i] = false;
	}

	int sum = 0;

	int pos = 0;
	for(int i = 0; i < n and pos != n - 1; i++){
		sum++;
		pos = control[pos];
	}

	if(pos != n - 1){
		std::cout << "NE";
		return 0;
	}

	for(int j = 0; j < n and control[pos] != 0; j++){
		if(j == 0){
			sum *= 2;
		}
		sum++;
		pos = control[pos];
	}

	if(control[pos] != 0){
		std::cout << "NE";
		return 0;
	}

	std::cout << sum;
	return 0;
}
