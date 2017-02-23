//============================================================================
// Name        : Sortiranje.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int iminja;
	cin >> iminja;

	string name[iminja];
	float vr[iminja];
	float counter = 0.001;
	for (int i = 0; i < iminja; i++) {
		cin >> name[i];
		vr[i] = 0;
		for (int j = 0; j < name[i].length(); j++) {
			vr[i] += name[i][j] - 64;
		}
		vr[i] = vr[i] / name[i].length();
		for (int j = i - 1; j >= 0; j--) {
			if (vr[i] == floor(vr[j])) {
				vr[i] += counter;
				counter += 0.001;
				break;
			}
		}
	}
	float leadingnum;
	int follower;
	for (int i = 0; i < iminja; i++) {
		leadingnum = 10000;
		for (int j = 0; j < iminja; j++) {
			if (leadingnum > vr[j] && vr[j] != 0) {
				leadingnum = vr[j];
				follower = j;
			}
		}
		cout << name[follower] << endl;
		vr[follower] = 0;
	}
	return 0;
}
