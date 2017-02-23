//============================================================================
// Name        : Lucky.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

std::string n, result = "boring";
int s2, s3, s5, s7;

int main() {
	std::cin >> n >> n;

	for(int i = 0; i < n.length(); i++){
		if(n[i] == '?'){
			s2++, s3++, s5++, s7++;
		} else if(n[i] == '2'){
			s2++, s3 = 0, s5 = 0, s7 = 0;
		} else if(n[i] == '3'){
			s2 = 0, s3++, s5 = 0, s7 = 0;
		} else if(n[i] == '5'){
			s2 = 0, s3 = 0, s5++, s7 = 0;
		} else if(n[i] == '7'){
			s2 = 0, s3 = 0, s5 = 0, s7++;
		} else{
			result = "boring";
			break;
		}

		if(s2 == 2 or s3 == 3 or s5 == 5 or s7 == 7){
			result = "cool";
		}
	}

	std::cout << result;
	return 0;
}
