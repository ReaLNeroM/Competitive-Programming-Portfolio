//============================================================================
// Name        : PlataKarta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b, k;
	float c;
	cin >> a >> b >> c;
	if ((a*100)>= c)
	{
		k=ceil(c/a);
	}
	else
	{
		k=100 + ceil((c-a*100)/b);
	}
	cout<<k;
	return 0;
}
