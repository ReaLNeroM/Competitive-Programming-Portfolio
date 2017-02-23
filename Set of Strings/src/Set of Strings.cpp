#include <iostream>
#include <deque>
#include <algorithm>

int n;
std::string str;
bool used[26];

bool check(int divisions, bool print){
	for(int i = 0; i < 26; i++){
		used[i] = false;
	}

	for(int i = 0; i < str.length(); i++){
		if(divisions > 0 and !used[str[i] - 'a']){
			divisions--;
			used[str[i] - 'a'] = true;

			if(print){
				std::cout << std::endl;
			}
		}

		if(print){
			std::cout << str[i];
		}
	}

	return (divisions == 0);
}
int main() {
	std::cin >> n >> str;


	if(check(n, false)){
		std::cout << "YES";
		check(n, true);
	} else{
		std::cout << "NO" << std::endl;
	}
	return 0;
}
