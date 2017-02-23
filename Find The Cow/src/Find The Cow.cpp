#include <iostream>

int main() {
	std::string str;
	std::cin >> str;

	int sum = 0, rightfound = 0;
	for(int i = str.length() - 2; i >= 0; i--){
		if(str[i] == ')' and str[i + 1] == ')'){
			rightfound++;
		} else if(str[i] == '(' and str[i + 1] == '('){
			sum += rightfound;
		}
	}

	std::cout << sum;
	return 0;
}
