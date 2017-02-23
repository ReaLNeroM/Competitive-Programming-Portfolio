#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int length, names;
	std::cin >> length >> names;

	int sum = 0;
	std::string parts[names];
	for(int i = 0; i < names; i++){
		std::cin >> parts[i];
		sum += parts[i].length();
	}

	ll ways[length + 1][(1 << names)];
	for(int i = 0; i <= length; i++){
		for(int j = 0; j < (1 << names); j++){
			ways[i][j] = 0;
		}
	}

	ways[length][(1 << names) - 1] = 1;

	for(int i = length - 1; i >= 0; i--){
		for(int j = 0; j <= (1 << names); j++){
			for(int k = 0; k < names; k++){
				if(parts[k].length() <= length - i and (j & (1 << k)) == 0){
					ways[i][j] += ways[i + parts[k].length()][j | (1 << k)];
				}
			}
			if(i < length){
				ways[i][j] += 26 * ways[i + 1][j];
			}
		}
	}

	std::cout << ways[0][0] << std::endl;

	if(ways[0][0] <= 30){
		if(names == 0){
			for(char i = 'a'; i <= 'z'; i++){
				std::cout << i << std::endl;
			}
		} else {
			int permutation[names];
			for(int i = 0; i < names; i++){
				permutation[i] = i;
			}

			do {
				for(int i = 0; i < names; i++){
					std::cout << parts[permutation[i]];
				}
				std::cout << std::endl;
			} while(std::next_permutation(permutation, permutation + names));
		}
	}
	return 0;

}
