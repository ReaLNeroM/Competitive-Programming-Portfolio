#include <iostream>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	int cases;
	std::cin >> cases;

	int res[cases];
	for(int test = 0; test < cases; test++){
		int coins, needed;
		std::cin >> coins >> needed;

		res[test] = -1;

		bool usable[needed + 1];
		for(int i = 0; i <= needed; i++){
			usable[i] = false;
		}

		usable[0] = true;
		bool won = false;
		for(int i = 0, inp; i < coins; i++){
			std::cin >> inp;
			if(i == (i & (-i))){
				won = true;

				for(int j = needed - inp; j >= 0; j--){
					if(usable[j]){
						usable[j + inp] = true;
					} else {
						won = false;
					}
				}
				for(int j = needed - inp + 1; j <= needed; j++){
					if(!usable[j]){
						won = false;
						break;
					}
				}

				if(won){
					res[test] = i + 1;
				}
			}
		}
	}

	for(int test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
	return 0;
}
