//============================================================================
// Name        : Triagolnici.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

struct coor{
	int x;
	int y;
};
int main() {
	int tocki;
	cin>>tocki;

	coor cor[tocki];
	for(int i = 0; i < tocki; i++){
		cin>>cor[i].x>>cor[i].y;
	}
	cout<< atan((cor[1].y - cor[0].y) / (cor[1].x - cor[0].x)) + atan((cor[2].y - cor[0].y) / (cor[2].x - cor[0].x));
	return 0;
}
