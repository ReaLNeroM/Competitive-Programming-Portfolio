#include <iostream>

int main() {
	std::string poraka;
	std::cin >> poraka;

	int max = 0, curr = 0, last = poraka[0];
	for(int i = 1; i < poraka.length(); i++){
		if(poraka[i] == last){
			curr++;
		} else {
			max = std::max(max, curr + 1);
			last = poraka[i];
			curr = 0;
		}
	}

	if(curr != 0){
		max = std::max(max, curr + 1);
	}

	std::cout << max;
	return 0;
}
