#include <iostream>

typedef long long ll;

int main() {
	ll goal;
	std::string str;
	std::cin >> str >> goal;


	if(str.length() % goal != 0){
		std::cout << "NO";
	} else {
		ll size = str.length() / goal, i;
		bool possible = true;
		for(i = 0; i < str.length(); i += size){
			for(ll j = 0; j < size; j++){
				if(str[i + j] != str[i + size - j - 1]){
					possible = false;
				}
			}
		}

		if(!possible){
			std::cout << "NO";
		} else {
			std::cout << "YES";
		}
	}
	return 0;
}
