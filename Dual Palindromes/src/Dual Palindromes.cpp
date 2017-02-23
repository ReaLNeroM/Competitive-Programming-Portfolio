/*
 ID: vlade.m1
 PROG: dualpal
 LANG: C++
 */

#include <fstream>

bool checker(std::string copy) {
	for (int i = 0; i < (int) copy.length(); i++) {
		if (copy[i] != copy[copy.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

std::string bconvert(int copy, int base) {
	std::string convert;
	while (copy != 0) {
		convert.insert(convert.begin(), 48 + copy % base);
		copy /= base;
	}
	return convert;
}

int main() {
	std::ifstream in;
	 std::ofstream out;
	 in.open("dualpal.in");
	 out.open("dualpal.out");
	int next, num;
	in >> next >> num;

	do {
		num++;
		bool mult = false;
		for (int i = 2; i <= 10; i++) {
			if (checker(bconvert(num, i))) {
				if (mult) {
					out << num << std::endl;
					next--;
					break;
				} else {
					mult++;
				}
			}
		}
	} while (next != 0);
}
