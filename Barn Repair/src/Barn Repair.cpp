/*
	ID: vlade.m1
	PROG: barn1
	LANG: C++
*/
#include <fstream>
#include <algorithm>

struct stall {
	int position;
	bool used = false;
};

bool stallcmp(stall a, stall b){
	return (a.position < b.position);
}

int main() {
	std::ifstream fin;
	std::ofstream fout;
	fin.open("barn1.in");
	fout.open("barn1.out");

	int boards, necessary;
	fin >> boards >> necessary >> necessary;
	stall st[necessary];

	for (int i = 0; i < necessary; i++) {
		fin >> st[i].position;
	}

	std::sort(st, st + necessary, stallcmp);
	int size = st[necessary - 1].position - st[0].position + 1;

	while (boards != 1) {
		int start = 0, max = 0;

		for (int i = 0; i < necessary - 1; i++) {
			if(st[i + 1].position - st[i].position - 1 > max and !st[i].used){
				max = st[i + 1].position - st[i].position - 1;
				start = i;
			}
		}

		if (max != 0){
			size -= max;
			st[start].used = true;
		}

		boards--;
	}

	fout << size << std::endl;
	return 0;
}
