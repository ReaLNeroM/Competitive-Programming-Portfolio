#include <iostream>

int main() {
	std::string str;
	std::cin >> str;

	int left = 0, right = 0;;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			left++;
		} else {
			right++;
		}
	}

	int res = 0;
	if(left == right - 1){
		res += left;
	} else if(right == left - 1){
		res += right;
	}

	std::cout << res;
	return 0;
}
