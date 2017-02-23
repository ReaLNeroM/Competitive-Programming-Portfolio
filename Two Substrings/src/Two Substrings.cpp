#include <iostream>

std::string str;


int main() {
	std::cin >> str;

	char needed[] = {'A', 'B'};
	for(int m = 0; m < 2; m++){
		int found = 0;
		for(int i = 0; i < str.length() - 1; i++){
			if(str[i] == needed[(m + (found % 2)) % 2] and str[i + 1] == needed[(m + ((found + 1) % 2)) % 2]){
				i++;
				found++;
				if(found == 2){
					std::cout << "YES";
					return 0;
				}
			}
		}
	}

	std::cout << "NO";
	return 0;
}
