#include <iostream>

typedef long long ll;

int main() {
	std::string str;
	std::cin >> str;

	int cost[str.length() + 1];
	cost[str.length()] = 0;

	for(int i = str.length() - 1; i >= 0; i--){
		cost[i] = cost[i + 1] + (str[i] == '0');
	}

	int min = str.length();
	int disabled = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '1'){
			min = std::min(min, disabled + cost[i]);
			disabled++;
		}
	}

	min = std::min(min, disabled);

	std::cout << min;
	return 0;
}
