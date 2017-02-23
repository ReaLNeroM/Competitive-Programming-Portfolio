//============================================================================
// Name        : Moj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int stefn,anan, stzb, anzb, leadingnum;
	bool anab;
	stzb = anzb = leadingnum = 0;
	for(int i = 0; i < 3; i++){
		cin>>stefn;
		if(stefn % (stefn % 10 + (stefn/10) % 10 + (stefn/100) % 10) == 0){
			stzb += 2;
			anzb -= 1;
		}
		cin>>anan;
		if(anan % (anan % 10 + (anan/10) % 10 + (anan/100) % 10) == 0){
			anzb += 2;
			stzb -= 1;
		}
		if(anan > leadingnum){
			leadingnum = anan;
			anab = 1;
		}
		if(stefn > leadingnum){
			leadingnum = stefn;
			anab = 0;
		}
	}
	cout<<stzb<<" "<< anzb<<endl;
	if(anzb < stzb || (!anab && anzb == stzb)){
		cout<<"Stefan";
	} else{
		cout<<"Ana";
	}
	return 0;
}
