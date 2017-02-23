/*
 ID: vlade.m1
 PROG: fc
 LANG: C++
*/

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("fc.in");
	std::ofstream fout("fc.out");
#endif

#include <cmath>

using namespace std;
typedef long long ll;

bool toleft(double x1, double y1, double x2, double y2, double x3, double y3){
	double res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if(res > 0.000001){
		return true;
	} else {
		return false;
	}
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	fin >> n;

	double x[n], y[n];

	int minindex = 0;

	for(int i = 0; i < n; i++){
		fin >> x[i] >> y[i];

		if(x[minindex] > x[i]){
			minindex = i;
		}
	}

	//2 ebe

	double res = 0;
	int sure = minindex, trypoint;
	do {
		trypoint = 0;
		for(int i = 1; i < n; i++){
			if(sure == trypoint or toleft(x[sure], y[sure], x[trypoint], y[trypoint], x[i], y[i])){
				trypoint = i;
			}
		}

		res += dist(x[sure], y[sure], x[trypoint], y[trypoint]);
		sure = trypoint;
	} while(sure != minindex);

	fout.precision(2);
	fout << fixed << res + dist(x[sure], y[sure], x[minindex], y[minindex]) << endl;
	return 0;
}
