#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

const int questions = 150;
const int eliminations = 5;
const double rightanswer = 1;
const double wronganswer = 0.25;

int main(){
	std::srand(std::time(NULL));

	int lost = 0;

	int givenans[eliminations], givenguess[eliminations];
	for(int i = 0; i < eliminations; i++){
		givenans[i] = givenguess[i] = 0;
	}

	for(int take = 0; take < 10000000; take++){

		double score = 0;
		for(int i = 0; i < questions; i++){
			int answer = std::rand() % eliminations, guess = std::rand() % eliminations;
			givenans[answer]++, givenguess[guess]++;

			if(answer == guess){
				score += rightanswer;
			} else {
				score -= wronganswer;
			}
		}

		if(score < -0.01){
			lost++;
		}
	}

	for(int i = 0; i < eliminations; i++){
		std:o:cout << givenans[i] << " " << givenguess[i] << std::endl;
	}

	std::cout << lost;
}

//1 -> 100%
//2 -> 75%
//3 -> 50%
//4 -> 25%
//5 ->  0%
