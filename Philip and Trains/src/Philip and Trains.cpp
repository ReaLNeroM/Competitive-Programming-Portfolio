#include <iostream>

typedef long long ll;

int main() {
	int cases;
	std::cin >> cases;

	std::string res[cases];
	for (int test = 0; test < cases; test++) {
//		int x, trains;
//		std::cin >> x >> trains;
		const int x = 16, trains = 4;

		int left[trains], right[trains], height[trains], pos;
		for (int i = 0; i < trains; i++) {
			left[i] = x;
			right[i] = -1000;
		}

		bool couldgo[3][x + 1];
		couldgo[0][x] = couldgo[1][x] = couldgo[2][x] = true;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < x; j++) {
				couldgo[i][j] = false;
				char ch;

				std::cin >> ch;
				if (ch >= 'A' and ch <= 'Z') {
					height[ch - 'A'] = i;
					left[ch - 'A'] = std::min(left[ch - 'A'], j - 2 * x);
					right[ch - 'A'] = std::max(right[ch - 'A'], j - 2 * x);
				} else if (ch == 's'){
					pos = i;
				}
			}
		}

		for (int i = x - 1; i >= 0; i--) {
		 	for (int k = 0; k < trains; k++) {
				left[k] += 2;
				right[k] += 2;
			}

			for(int j = 0; j < 3; j++){
				if(couldgo[j][i + 1]){
					couldgo[j][i] = true;
				}
			}
			for(int j = 1; j < 3; j++){
				if (couldgo[j - 1][i + 1]) {
					couldgo[j][i] = true;
				}
			}
			for (int j = 0; j < 2; j++) {
				if (couldgo[j + 1][i + 1]) {
					couldgo[j][i] = true;
				}
			}

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < trains; k++) {
					if(j == height[k] and i >= left[k] and i <= right[k]){
						couldgo[j][i] = false;
					}
				}

			}
		}

		if(couldgo[pos][0]){
			res[test] = "YES";
		} else {
			res[test] = "NO";
		}
	}

	for(int test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
	return 0;
}
