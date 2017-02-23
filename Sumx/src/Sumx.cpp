#include <iostream>
#include <algorithm>

int main() {
	int numbers, goal;
	std::cin >> numbers;

	int values[numbers];

	for(int i = 0; i < numbers; i++){
		std::cin >> values[i];
	}

	std::cin >> goal;

	std::sort(values, values + numbers);

	int atcurr = numbers - 1, possible = 0, samewon = 1;

	for(int i = 0; i < numbers - 1 and atcurr > i; i++){
		while(values[i] + values[atcurr] > goal and atcurr > i){
			atcurr--;
		}
		if(values[i] + values[atcurr] == goal and values[i] != values[atcurr]){
			possible += samewon;
			if(values[i] == values[i + 1]){
				samewon++;
			} else{
				samewon = 1;
			}
		}
	}

	std::cout << possible;
	return 0;
}
