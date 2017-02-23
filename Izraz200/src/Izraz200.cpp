#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

std::string str, cifri;
int max[8], min[8];

void removebrackets() {
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			int left = 1, j = i;
			bool opposite = false;
			if(i != 0 and str[i - 1] == '-'){
				opposite = true;
			}

			while(left > 0){
				j++;

				if(opposite and left == 1 and str[j] == '+'){
					str[j] = '-';
				} else if(opposite and left == 1 and str[j] == '-'){
					str[j] = '+';
				} else if(str[j] == '('){
					left++;
				} else if(str[j] == ')'){
					left--;
				}
			}

			str.erase(str.begin() + i);
			str.erase(str.begin() + j - 1);
		}
	}

	char sign = '+';
	int count = 0;

	str += '0';
	for(int i = 0; i < str.length(); i++){
		if(i == str.length() - 1 or str[i] == '+' or str[i] == '-'){
			if(count > 0){
				if(sign == '+'){
					max[count]++;
				} else {
					min[count]++;
				}
			}

			sign = str[i];
			count = 0;
		} else if(str[i] == '?'){
			count++;
		}
	}

	if(count > 0){
		if(sign == '+'){
			max[count]++;
		} else {
			min[count]++;
		}
	}
}

int assign() {
	int result = 0, power = 1;
	for(int i = 1; i < 7; i++){
		power *= 10;
	}
	for(int i = 7; i > 0; i--){
		while(max[i] != 0){
			result += (cifri[0] - '0') * power;

			cifri.erase(cifri.begin());

			max[i - 1]++;
			max[i]--;
		}

		power /= 10;
	}

	power = 1;
	for(int i = 1; i < 7; i++){
		power *= 10;
	}
	for(int i = 7; i > 0; i--){
		while(min[i] != 0){
			result -= (cifri[cifri.length() - 1] - '0') * power;

			cifri.erase(cifri.end() - 1);

			min[i - 1]++;
			min[i]--;
		}

		power /= 10;
	}

	return result;
}

int main() {
	std::cin >> str >> cifri;

	for(int i = 0; i < 8; i++){
		min[i] = max[i] = 0;
	}
	std::sort(cifri.begin(), cifri.end(), std::greater <int>());

	removebrackets();

	std::cout << assign();
	return 0;
}
