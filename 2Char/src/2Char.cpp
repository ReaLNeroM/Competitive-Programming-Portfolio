#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int words;
	std::cin >> words;

	std::string str[words];
	for(int i = 0; i < words; i++){
		std::cin >> str[i];
	}

	int max = 0;

	for(char i = 'a'; i <= 'z'; i++){
		for(char j = 'a'; j <= 'z'; j++){
			int coverage = 0;
			for(int k = 0; k < words; k++){
				coverage += str[k].length();
				for(int l = 0; l < str[k].length(); l++){
					if(str[k][l] != i and str[k][l] != j){
						coverage -= str[k].length();
						break;
					}
				}
			}

			max = std::max(max, coverage);
		}
	}
	std::cout << max;
	return 0;
}
