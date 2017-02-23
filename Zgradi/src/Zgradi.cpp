//============================================================================
// Name        : Zgradi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int zgradi, curr, max = 0;
	long long zbir = 0;
	cin >> zgradi;
	for (int i = 0; i < zgradi; i++) {
		cin >> curr;
		if (curr > max) {
			zbir += (curr - max) * i;
			max = curr;
		} else {
			zbir += max - curr;
		}
	}

	cout << zbir;
	return 0;
}
