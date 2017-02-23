//============================================================================
// Name        : Kod.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	std::string code;
	std::cin >> code;

	long long perms[code.length() + 1];

	for(int i = 0; i < code.length(); i++){
		perms[i] = 0;
	}
	perms[code.length()] = 1;

	for(int i = code.length() - 1; i >= 0; i--){
		if(code[i] != '0'){
			perms[i] += perms[i + 1];
		}
		if(i != code.length() - 1 and ((code[i] == '2' and code[i + 1] < '7') or (code[i] == '1'))){
			perms[i] += perms[i + 2];
		}
	}

	std::cout << perms[0];
	return 0;
}
