#include <iostream>

int main() {
	long long books;
	std::cin >> books;

	long long curr = 1, log = 1, required = 0;

	while(curr * 10 <= books){
		required += (curr * 10 - curr) * log;
		log++;
		curr *= 10;
	}

	required += (books - curr + 1) * log;

	std::cout << required;
	return 0;
}
