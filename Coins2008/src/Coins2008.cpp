#include <iostream>

int main() {
	int take[3], cases;
	take[0] = 1;
	std::cin >> take[1] >> take[2] >> cases;

	bool winnable[10000001];

	for(int i = 0; i <= 1000000; i++){
		winnable[i] = false;
		for(int k = 0; k < 3 and take[k] <= i; k++){
			if(!winnable[i - take[k]]){
				winnable[i] = true;
				break;
			}
		}
	}

	char res[cases];
	for(int i = 0, query; i < cases; i++){
		std::cin >> query;
		res[i] = (winnable[query]) ? 'A' : 'B';
	}
	for(int i = 0; i < cases; i++){
		std::cout << res[i];
	}
	return 0;
}
