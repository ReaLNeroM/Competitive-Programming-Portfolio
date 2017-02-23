#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	int palms, queries;
	std::cin >> palms >> queries;

	int height[palms];
	for(int i = 0; i < palms; i++){
		std::cin >> height[i];
	}

	int cases = 0, res[queries];

	for(int test = 0; test < queries; test++){
		std::string command;
		int a, b;
		std::cin >> command >> a >> b;

		if(command == "REPLACE"){
			height[a - 1] = b;
		} else {
			int swapping = 0;
			bool found = false, increasing;
			for(int i = a; i < b; i++){
				if(!found and height[i] != height[i - 1]){
					if(height[i] > height[i - 1]){
						found = true;
						increasing = false;
					} else {
						found = true;
						increasing = true;
					}
				} else if(height[i] != height[i - 1]){
					if(increasing and height[i] > height[i - 1]){
						increasing = false;
					} else if(!increasing and height[i] < height[i - 1]){
						increasing = true;
					} else {
						swapping++;
					}
				} else {
					swapping++;
				}
			}
			res[cases] = swapping;
			cases++;
		}
	}

	for(int i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
