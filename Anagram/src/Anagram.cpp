//============================================================================
// Name        : Anagram.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int inp, anagram = 0;
	cin>>inp;
	string fir, sec;
	for(int i = 0; i < inp; i++){
		cin>>fir>>sec;
		for(int j = 0; j < fir.length(); ){
			int k;
			for(k = 0; k < sec.length();k++){
				if(fir[j] == sec[k]){
					sec[k] = 'a';
					j++;
					if(j == fir.length()) anagram++;
					break;
				}
			}
			if(k == sec.length()) break;
		}
	}

	cout<<anagram;
	return 0;
}
