#include <iostream>

typedef long long ll;

void recurse(int time){

}

int main() {
	int people, time;
	double probability;
	std::cin >> people >> probability >> time;

	double expected[time + 1][people + 1];
	for(int j = 0; j <= time; j++){
		expected[j][0] = 0;
	}
	for(int i = 0; i <= people; i++){
		expected[0][i] = 0;
	}

	expected[1][1] = probability;
	for(int i = 1; i <= time; i++){
		for(int j = 1; j <= people; j++){
			expected[i][j] *= expected[i - 1][j];
		}

		expected[i][people] = expected[i - 1][people];
	}

	double average = 0;
	for(int i = 0; i <= people; i++){
		average += expected[time][i];
	}

	average /= (double) people + 1;

	std::cout << average;
	return 0;
}
