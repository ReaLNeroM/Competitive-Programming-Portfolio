//============================================================================
// Name        : Zbor.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string word;
	cin>>word;
	int tezina = 0;
	for(int i = 0; i < word.length() - 1;i++){
		if(word[i] != 'a' && word[i] != 'e' &&
		   word[i] != 'i' && word[i] != 'o' &&
		   word[i] != 'u' &&
		   word[i + 1] != 'a' && word[i + 1] != 'e' &&
		   word[i + 1] != 'i' && word[i + 1] != 'o' &&
		   word[i + 1] != 'u'){
				tezina++;
		}
	}

	cout<<tezina;
	return 0;
}
