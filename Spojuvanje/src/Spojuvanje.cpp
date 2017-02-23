//============================================================================
// Name        : Spojuvanje.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>

struct piece{
	int comp;
	double val;

	bool operator<(const piece &x) const{
		return (val < x.val);
	}
};

int main() {
	int nums;
	std::cin >> nums;

	int best[7];
	best[0] = 9, best[1] = 99, best[2] = 999, best[3] = 9999, best[4] = 99999, best[5] = 999999, best[6] = 9999999;
	piece pieces[nums];
	for(int i = 0; i < nums; i++){
		std::cin >> pieces[i].comp;

		pieces[i].val = ((double) best[(int) std::log10(pieces[i].comp)]) / pieces[i].comp;
	}


	std::sort(pieces, pieces + nums);

	for(int i = 0; i < nums; i++){
		std::cout << pieces[i].comp;
	}
	return 0;
}
