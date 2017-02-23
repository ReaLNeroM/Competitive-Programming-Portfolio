//============================================================================
// Name        : Kuglanje.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int redici;
	cin >> redici;

	int vred[2][redici], leadingnum = 0;
	memset(vred, 0, sizeof(vred));
	cin >> vred[0][0];
	for (int i = 1, adjust = 0; i < redici; i++, adjust++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> vred[i % 2][j];

			if (adjust == 2)
				adjust = 0;

			if (j == 0)
				vred[i % 2][j] += vred[adjust][0];
			else if (j == i + 1)
				vred[i % 2][j] += vred[adjust][i - 1];
			else
				vred[i % 2][j] += max(vred[adjust][j - 1], vred[adjust][j]);

			if (i == redici - 1 && vred[i % 2][j] > leadingnum)
				leadingnum = vred[i % 2][j];

		}
	}

	cout << leadingnum;
	return 0;
}
