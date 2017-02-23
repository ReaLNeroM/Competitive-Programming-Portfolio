//============================================================================
// Name        : Cezarova.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int code;
	string command;
	cin>>code;
	cin>>command;

	for(int i = 0; i < command.length();i++){
        if(command[i] + code > 122){
			cout<<(char) (244 - command[i] - code);
		} else{
		cout<<(char) (command[i] + code);
		}
	}
	return 0;
}
