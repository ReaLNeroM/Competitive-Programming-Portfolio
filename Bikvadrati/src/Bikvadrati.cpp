#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;

	int res = 0;
	bool used[b + 1];
	for(int i = 0; i <= b; i++){
		used[i] = false;
	}
	for(int i = 0; i < b; i++){
		for(int j = 0; j < b; j++){
			if(i * i + j * j >= a and i * i + j * j <= b){
				used[i * i + j * j] = true;
			}
		}
	}

	for(int i = 0; i <= b; i++){
		if(used[i]){
			res++;
		}
	}

	std::cout << res;
	return 0;
}
