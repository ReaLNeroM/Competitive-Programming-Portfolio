#include <iostream>
#include <algorithm>

int main(){
	int n, period;
	std::cin >> n >> period;

	std::string str;
	std::cin >> str;

	int res = 0, changes[26];
	for(int i = 0; i < period; i++){
		for(int j = 0; j < 26; j++){
			changes[j] = n / period;
		}

		for(int j = i; j < n; j += period){
			changes[str[j] - 'A']--;
		}

		res += *std::min_element(changes, changes + 26);
	}

	std::cout << res;
}
