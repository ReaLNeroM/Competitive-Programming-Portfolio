//============================================================================
// Name        : Perfect.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

int num, start;
bool used[32001];
int sum[32001];

bool recurse(int pos, bool print = false){
	if(pos > num or pos < 0 or (!print and used[pos])){
		return false;
	} else if(sum[pos] == start and !print){
		start = pos;
		recurse(sum[pos], true);
		return true;
	}
	if(print){
		std::cout << pos << " ";
		if(pos == start){
			return true;
		}
		return recurse(sum[pos], print);
	}
	used[pos] = true;

	return recurse(sum[pos], print);
}

int main(){
	std::cin >> num;

	for(int i = 1; i <= num; i++){
		used[i] = false;
		sum[i] = 1;
		for(int j = 2; j <= std::sqrt(i); j++){
			if(i % j == 0){
				sum[i] += j;
				if(j != i / j){
					sum[i] += i / j;
				}
			}
		}
	}

	for(int i = 1; i <= num; i++){
		start = i;
		if(!used[i] and recurse(i)){
			std::cout << std::endl;
		}
	}
}
