/*
 ID: vlade.m1
 PROG: friday
 LANG: C++
 */
#include <fstream>

#define mesec i%12
#define godina i/12
std::ifstream inp;
std::ofstream out;

int main() {
	inp.open("friday.in");
	out.open("friday.out");
	int godini, currday = 0, day[7] = { };
	inp >> godini;

	for (int i = 0; i < godini * 12; i++) {
		day[currday % 7]++;
		if (mesec == 3 or mesec == 5 or mesec == 8 or mesec == 10) {
			currday += 2;
		} else if (mesec == 1) {
			if ((1900 + godina) % 400 == 0
					or ((1900 + godina) % 100 != 0 and (1900 + godina) % 4 == 0)) {
				currday++;
			}
		} else {
			currday += 3;
		}
	}

	for (int i = 0; i < 6; i++) {
		out << day[i] << " ";
	}
	out << day[6] << std::endl;

	return 0;
}
