#include <iostream>

typedef long long ll;

int main() {
	int letters, dist;
	std::cin >> letters >> dist;

	std::string first, second;
	std::cin >> first >> second;

	int same = 0;
	for(int i = 0; i < letters; i++){
		if(first[i] == second[i]){
			same++;
		}
	}

	if(letters - same == dist or letters == dist){
		for(int i = 0; i < letters; i++){
			if(first[i] == second[i] and letters != dist){
				std::cout << first[i];
			} else {
				if(first[i] != 'a' and second[i] != 'a'){
					std::cout << 'a';
				} else if(first[i] != 'b' and second[i] != 'b'){
					std::cout << 'b';
				} else {
					std::cout << 'c';
				}
			}
		}
	} else if((letters - same) % 2 == 0 and (letters - same) / 2 == dist){
		int used1 = 0, used2 = 0;
		for(int i = 0; i < letters; i++){
			if(first[i] == second[i]){
				std::cout << first[i];
			} else {
				if(used1 != dist){
					std::cout << first[i];
					used1++;
				} else if(used2 != dist){
					std::cout << second[i];
					used2++;
				} else {
					std::cout << "!!!!";
					used2 /= 0;
				}
			}
		}
	} else {
		std::cout << -1;
	}
	return 0;
}
