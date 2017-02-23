#include <iostream>
#include <algorithm>
#include <functional>

int main() {
	int students;
	std::cin >> students;

	int quality[students];

	for(int i = 0; i < students; i++){
		std::cin >> quality[i];
	}

	for(int i = 0, bigger; i < students; i++){
		bigger = 0;

		for(int j = 0; j < students; j++){
			if(quality[i] < quality[j]){
				bigger++;
			}
		}

		std::cout << bigger + 1 << " ";
	}
	return 0;
}
