#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	int cases;
	std::cin >> cases;

	bool found[1000000];
	int res[cases];
	for(int test = 0; test < cases; test++){
		std::string str;
		std::cin >> str;

		for(int i = 0; i < 1000000; i++){
			found[i] = false;
		}

		for(int i = 0; i < str.length(); i++){
			int num = 0;
			for(int j = i; j < std::min(i + 6, (int) str.length()); j++){
				num += str[j] - '0';
				found[num] = true;
				num *= 10;
			}
		}

		for(int i = 0; i < 1000000; i++){
			if(!found[i]){
				res[test] = i;
				break;
			}
		}
	}

	for(int test = 0; test < cases; test++){
		std::cout << res[test] << "\n";
	}
	return 0;
}
