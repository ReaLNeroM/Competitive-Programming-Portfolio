//============================================================================
// Name        : Makedonski.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int stihovi, brojsodrzi = 0;
	cin>>stihovi;
	stihovi++;
	string stih[stihovi];
	char samoglaski[] = {"АЕИОУаеиоу\'"};
	for(int i = 0; true ; i++){
		getline(cin, stih[i]);
		brojsodrzi = 0;
		for(int j = 0; j < stih[i].length() + 1; j++){
			bool nothing = false;
			for(int k = 0; k < sizeof(samoglaski)/sizeof(samoglaski[0]); k++){
				if(stih[i][j] == samoglaski[k]){
					brojsodrzi++;
				}

				if(stih[i][j] == '�' || stih[i][j] == '�'){
					if(j != 0 && j != stih[i].length() - 1){
						if(stih[i][j - 1] != samoglaski[k] && stih[i][j + 1] != samoglaski[k] && stih[i][j - 1] != ' ' && stih[i][j + 1] != ' ' && stih[i][j - 1] != '\''){
							nothing = false;
					}
				}
			}
			}
			if(nothing){
				brojsodrzi++;
			}
		}
		cout<<brojsodrzi - 1<<endl;
	}
	return 0;
}
