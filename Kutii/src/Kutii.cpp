//============================================================================
+// Name        : Kutii.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int pred, kutii;
	cin >> pred >> kutii;

	vector<int> gp, gk;
	int p, k, incr = 0;
	for (int i = 0; i < pred; i++) {
		cin >> p;
		gp.push_back(p);
	}
	for (int i = 0; i < kutii; i++) {
		cin >> k;
		gk.push_back(k);
		if (gk[i] >= gp[incr])
			incr++;
	}
	cout << incr;
	return 0;
}
