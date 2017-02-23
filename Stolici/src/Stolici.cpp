//============================================================================
// Name        : Stolici.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

struct timer {
	int time;
	int adder;
};

int process(std::string copy) {
	int result = 0;
	result += (copy[0] - 48) * 10 * 60 * 60;
	result += (copy[1] - 48) * 60 * 60;
	result += (copy[3] - 48) * 10 * 60;
	result += (copy[4] - 48) * 60;
	result += (copy[6] - 48) * 10;
	result += (copy[7] - 48);
	return result;
}

int main() {
	int korisnici;
	std::cin >> korisnici;

	std::vector<timer> vreme(korisnici * 2);
	std::string copier;

	for (int i = 0; i < korisnici; i++) {
		std::cin >> copier;
		vreme[i * 2].time = process(copier);
		vreme[i * 2].adder = 1;

		std::cin >> copier;
		vreme[i * 2 + 1].time = process(copier);
		vreme[i * 2 + 1].adder = -1;
	}

	int curr = 0, max = 0, follower;
	for (int i = 0; i < korisnici * 2; i++) {
		follower = 0;
		for(int j = 0; j < vreme.size(); j++){
			if(vreme[follower].time > vreme[j].time or (vreme[follower].time == vreme[j].time and vreme[j].adder == 1)){
				follower = j;
			}
		}
		curr += vreme[follower].adder;
		vreme.erase(vreme.begin() + follower);
		max = std::max(curr, max);
	}

	std::cout << max;
	return 0;
}
