#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::string start;
	std::cin >> start;

	int turns = 0, shakes = 0;

	bool turned;
	do {
		turns++;
		turned = false;
		for(int i = 0; i < start.length() - 1; i++){
			if(start[i] == 'R' and start[i + 1] == 'L'){
				start[i] = 'L';
				start[i + 1] = 'R';
				i++;
				turned = true;
				shakes++;
			}
		}
	} while(turned);

	std::cout << turns - 1 << ' ' << shakes << std::endl;
	return 0;
}
