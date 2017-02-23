//============================================================================
// Name        : Marathon.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <cmath>
using namespace std;

struct coor{
	int x, y;
};
int manhat(coor a, coor b){
	return std::fabs(a.x - b.x) + std::fabs(a.y - b.y);
}

int main() {
	ifstream myf;
	ofstream mof;
	myf.open("marathon.in");
	mof.open("marathon.out");
	int dots;
	myf>>dots;
	coor c[dots];

	for(int i = 0; i < dots; i++){
		myf>>c[i].x>>c[i].y;
	}

	long long max = 0;
	int follower;

	for(int i = 1; i < dots- 1; i++){
		if((manhat(c[i - 1], c[i]) + manhat(c[i], c[i + 1])) - manhat(c[i - 1], c[i + 1]) > max){
			max = manhat(c[i - 1], c[i]) + manhat(c[i], c[i + 1]) - manhat(c[i - 1], c[i + 1]);
			follower = i - 1;
		}
	}

	long long result = 0;

	for(int i = 0; i < dots - 1; i++){
		if(i == follower){
			result += manhat(c[i], c[i + 2]);
			i += 1;
			continue;
		}

		result += manhat(c[i], c[i + 1]);
	}

	mof<<result;
	return 0;
}
