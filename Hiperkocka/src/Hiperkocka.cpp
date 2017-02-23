#include <iostream>
#include <algorithm>

int main() {
	int vertices, nth, useless;
	std::cin >> vertices >> nth >> useless;

	std::string str = "";

	for(int copy = nth; copy >= 1; copy /= 2){
		str.push_back(copy % 2 + '0');
	}

	std::reverse(str.begin(), str.end());

	std::string second = str;
	for(int i = 0; i < str.length(); i++){

	}
	return 0;
}
