//============================================================================
// Name        : Prozorci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct prozorec{
	int x, y, visocina, sirocina;
};
int main() {
	int prozorci;
	cin>>prozorci;
	prozorec pr[prozorci];
	for(int i = 0; i < prozorci; i++){
		cin>>pr[i].x>>pr[i].y;
		cin>>pr[i].sirocina>>pr[i].visocina;
	}
	int xcl, ycl;
	cin>>xcl>>ycl;

	bool found = false;
	for(int i = prozorci - 1; i >= 0; i--){
		if(xcl >= pr[i].x and xcl < (pr[i].x + pr[i].sirocina) and
				ycl >= pr[i].y and ycl < (pr[i].y + pr[i].visocina)){
			cout<<"prozorec "<< i + 1;
			found = true;
			break;
		}
	}

	if(!found){
		cout<<"pozadina";
	}
	return 0;
}
