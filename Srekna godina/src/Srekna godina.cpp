#include <iostream>

int main() {
	bool used[10];
	for(int i = 0; i < 10; i++){
		used[i] = false;
	}

	std::string year;
	std::cin >> year;

	for(int i = 0; i < year.length(); i++){
		if(used[year[i] - '0']){
			std::cout << "DA";
			return 0;
		} else {
			used[year[i] - '0'] = true;
		}
	}

	std::cout << "NE";
	return 0;
}
