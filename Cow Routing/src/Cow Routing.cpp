#include <fstream>

int main() {
	std::ifstream fin;
	std::ofstream out;
	fin.open("cowroute.in");
	out.open("cowroute.out");
	int start, end, num;
	fin >> start >> end >> num;

	int cena, flc, state, copy, mincost = 100000;
	for (int i = 0; i < num; i++) {
		fin >> cena >> flc;
		state = 0;
		for (int i = 0; i < flc; i++) {
			fin >> copy;
			if (state == 1 and copy == end) {
				mincost = std::min(mincost, cena);
			} else if(copy == start){
				state = 1;
			}
		}
	}

	if(mincost != 100000){
		out << mincost;
	} else{
		out << -1;
	}
	return 0;
}
