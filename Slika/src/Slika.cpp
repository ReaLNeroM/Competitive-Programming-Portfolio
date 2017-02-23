//============================================================================
// Name        : Slika.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string inp;
	int x = 0, y = 1;
	getline(cin, inp);
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] != ' ') {
			x++;
		}
	}

	while (true) {
		if (inp[inp.length() - 1] == '3') {
			break;
		}
		getline(cin, inp);
		y++;

	}
	cout << y << " " << x;
	return 0;
}
