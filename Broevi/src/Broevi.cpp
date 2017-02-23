//============================================================================
// Name        : Broevi.cpp
// Author      : 
// Version     :
// copyyright   : Your copyyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	bool usable[3];

	for (int i = 0; i < 3; i++) {
		string data, used;
		int copy, denovi = 31, zbir = 0;
		bool prestap = false;
		usable[i] = true;
		cin >> data;

		used = data[4], used += data[5], used += data[6];
		copy = atoi(used.c_str());

		if (copy >= 600) {
			copy += 1000;
		} else {
			copy += 2000;
		}

		if ((copy % 400 == 0) or (copy % 4 == 0 and copy % 100 != 0)) {
			prestap = true;
		}

		used = data[2], used += data[3];
		copy = atoi(used.c_str());
		if (!(copy >= 1 and copy <= 12)) {
			usable[i] = false;
			continue;
		}

		if (copy == 4 or copy == 6 or copy == 9 or copy == 11) {
			denovi = 30;
		} else if (copy == 2) {
			if (prestap) {
				denovi = 29;
			} else {
				denovi = 28;
			}
		}

		used = data[0], used += data[1];
		copy = atoi(used.c_str());

		if (!(copy <= denovi and copy > 0)) {
			usable[i] = false;
			continue;
		}

		used = data[7];
		copy = atoi(used.c_str());

		if (copy != 1 and copy != 6 and copy != 9) {
			usable[i] = false;
			continue;
		}
		for (int j = 0; j < 8; j++) {
			used = data[j];
			copy = atoi(used.c_str());
			zbir += copy * copy;
		}

		used = data[8];
		copy = atoi(used.c_str());

		if (zbir % 7 != copy) {
			usable[i] = false;
		}
	}

	for(int i = 0; i < 3; i++){
		cout<<usable[i]<<endl;
	}

	return 0;
}
