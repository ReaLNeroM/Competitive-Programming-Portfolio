/*
 ID: vlade.m1
 PROG: milk2
 LANG: C++
 */

#include <iostream>
#include <algorithm>

struct tim {
	int min;
	bool ent;
	bool tcomp(tim a, tim b){
		return(a.min < b.min);
	}
};

int main() {
	int farmers;
	std::cin >> farmers;
	farmers *= 2;
	tim t[farmers];

	for (int i = 0; i < farmers; i++) {
		std::cin >> t[i].min;
		(i % 2 == 0) ? t[i].ent = true : t[i].ent = false;
	}
	std::sort(t, t + farmers, tcomp);

	int currf = 0, maxful = 0, maxemp = 0, startt = -1, endt = -1;
	for (int i = -1; i < farmers;) {
		do{
		i++;
		(t[i].ent) ? currf++ : currf--;
		} while(i < farmers - 1 and t[i].min == t[i + 1].min);
		if (currf > 0) {
			if (endt != -1) {
				maxemp = std::max(maxemp, t[i].min - endt);
				endt = -1;
			}
			if (startt == -1) {
				startt = t[i].min;
			}

		} else {
			if (startt != -1) {
				maxful = std::max(maxful, t[i].min - startt);
				startt = -1;
			}
			if (endt == -1) {
				endt = t[i].min;
			}
		}
	}

	std::cout << maxful << " " << maxemp << std::endl;
	return 0;
}
