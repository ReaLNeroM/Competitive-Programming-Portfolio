/*
ID: vlade.m1
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

//#define fin cin
//#define fout cout

std::ifstream fin("fence9.in");
std::ofstream fout("fence9.out");

int main() {
	int x1, y1, endx;
	fin >> x1 >> y1 >> endx;

	int res = 0;

	if(x1 <= endx){
		double yslope = ((double) y1) / x1;
		double ypos = 0;

		for(int i = 1; i <= x1; i++){
			ypos += yslope;

			if(i != endx){
				int rup = (int) (ypos - 0.00000001);
				res += rup;
			}
		}

		ypos = y1;
		yslope = (double) (y1) / (endx - x1);

		for(int i = x1 + 1; i < endx; i++){
			ypos -= yslope;

			int rup = (int) (ypos - 0.00000001);
			res += rup;
		}
	} else {
		double yslope = ((double) y1) / x1;
		double ypos = 0;

		for(int i = 1; i <= endx; i++){
			ypos += yslope;

			int rup = (int) (ypos - 0.00000001);
			res += rup;
		}

		double byslope = (double) y1 / (x1 - endx);
		double bypos = 0;

		for(int i = endx + 1; i <= x1; i++){
			ypos += yslope;
			bypos += byslope;

			int rup = (int) (ypos - 0.0000001), rdown = (int) (bypos + 1.00000001);

			if(rup >= rdown){
				res += rup - rdown + 1;
			}
		}
	}

	fout << res << endl;
	return 0;
}
