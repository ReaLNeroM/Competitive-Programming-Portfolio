#include <iostream>

typedef long long ll;

int main() {
	std::string str;
	std::cin >> str;

	int currlength = 1, maxlength = 0;
	for(int i = 1; i < str.length(); i++){
		if(str[i - 1] == str[i]){
			currlength++;
		} else {
			maxlength = std::max(currlength, maxlength);
			currlength = 1;
		}
	}

	maxlength = std::max(currlength, maxlength);

	std::cout << str.length() - maxlength;
	return 0;
}
