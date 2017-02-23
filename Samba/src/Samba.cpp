#include <iostream>
#include <map>

int main() {
	int dancers, period;
	std::cin >> dancers >> period;

	std::map<int, int> list;
	int id[dancers];
	for(int i = 0; i < dancers; i++){
		std::cin >> id[i];
		list[id[i]]++;
	}

	for(int i = 0; i < dancers; i++){
		if(list[id[i]] % period != 0){
			std::cout << id[i];
			break;
		}
	}

	return 0;
}
