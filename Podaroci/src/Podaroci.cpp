//============================================================================
// Name        : Podaroci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

struct predmet{
	int x;
	int y;
}a, inp;
int main() {
	int pred, count = 0;
	cin>>a.x>>a.y>>pred;
	vector<predmet> pi;
	for(int i = 0; i < pred; i++){
		cin>>inp.x>>inp.y;
		if((inp.x <= a.x and inp.y <= a.y) or (inp.x <= a.y and inp.y <= a.x)){
			count++;
			pi.push_back(inp);
		}
	}

	cout<<count<<endl;

	for(int i = 0; i < count;i++){
		cout<<pi[i].x<<" "<<pi[i].y<<endl;
	}
	return 0;
}
