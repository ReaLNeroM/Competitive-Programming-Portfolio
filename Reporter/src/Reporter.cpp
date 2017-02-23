/*
//============================================================================
// Name        : Reporter.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int reporteri;
	cin >> reporteri;
	int bf[reporteri], bfpass[reporteri];
	bool passed[reporteri];
	for (int i = 0; i < reporteri; i++) {
		bfpass[i] = -1;
		passed[i] = false;
		cin >> bf[i];
		bf[i]--;
	}
	int najgolema = 0;
	for (int i = 0, vrski, ripanje; i < reporteri; i++) {
		if(passed[i] == true){
			continue;
		}
		vrski = 0;
		ripanje = i;
		do {
			vrski++;
			bfpass[ripanje] = i;
			ripanje = bf[ripanje];
			passed[ripanje] = true;
		} while (bfpass[ripanje] != i);

		najgolema = max(vrski,najgolema);
	}

	cout << najgolema;
	return 0;
}
*/

#include <iostream>
#include <vector>

int func(int start, std::vector<int> &cost, std::vector<int> &link){
	if(cost[start] == -1){
		cost[start] = 1;
		cost[start] += func(link[start], cost, link);
	}

	return cost[start];
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> cost, link;
	cost.resize(n), link.resize(n);


	for(int i = 0; i < n; i++){
		cost[i] = -1;
		std::cin >> link[i];
		link[i]--;
	}

	int max = 0;
	for(int i = 0; i < n; i++){
		max = std::max(max, func(i, cost, link));
	}

	std::cout << max;
	return 0;
}
