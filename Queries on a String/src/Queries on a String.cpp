#include <iostream>

typedef long long ll;

std::string str;

void cycle(int left, int right, int c){
	std::string copy = str;

	for(int i = left; i < right; i++){
		str[left + ((i - left) + c) % (right - left)] = copy[i];
	}

}

int main() {
	std::cin >> str;

	int queries;
	std::cin >> queries;
	for(int i = 0, left, right, k; i < queries; i++){
		std::cin >> left >> right >> k;

		left--;
		cycle(left, right, k);
	}
	std::cout << str << std::endl;
	return 0;
}
