#include <iostream>

typedef long long ll;

int main() {
	int computers;
	std::cin >> computers;

	int pieces[computers];
	bool used[computers];
	for(int i = 0; i < computers; i++){
		std::cin >> pieces[i];
		used[i] = false;
	}

	int collected = 0, left = computers, rounds = 0;
	while(left > 0){
		for(int i = 0; i < computers; i++){
			if(!used[i] and collected >= pieces[i]){
				collected++;
				used[i] = true;
				left--;
			}
		}
		rounds++;
		if(left <= 0){
			break;
		}

		for(int i = computers - 1; i >= 0; i--){
			if(!used[i] and collected >= pieces[i]){
				collected++;
				used[i] = true;
				left--;
			}
		}
		rounds++;
		if(left <= 0){
			break;
		}
	}

	std::cout << rounds - 1;
	return 0;
}
