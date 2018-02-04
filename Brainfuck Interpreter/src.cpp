#include <iostream>
#include <stack>
#include <string>
#include <deque>
#include <stdlib.h>

void error(){
	std::cerr << "INVALID COMMAND" << std::endl;
	std::cerr << "TERMINATING" << std::endl;
	exit(EXIT_FAILURE);	
}

int main(){
	std::string input;
	std::cin >> input;

	std::stack<int> s;

	std::deque<char> array(0); //2 byte length, not single byte

	int pointer_array = 0;

	for(int i = 0; i < input.size(); i++){
		if(input[i] == '+'){
			array[pointer_array]++;
			if(array[pointer_array] > 255){
				array[pointer_array] = 255;
			}
		} else if(input[i] == '-'){
			array[pointer_array]--;
			// if(array[pointer_array] < 0){
			// 	array[pointer_array] = 0;
			// }
		} else if(input[i] == '<'){
			pointer_array--;
			if(pointer_array == -1){
				array.push_front(0);
				pointer_array++;
			}
		} else if(input[i] == '>'){
			pointer_array++;
			if(pointer_array == array.size()){
				array.push_back((char) 0);
			}
		} else if(input[i] == '.'){
			std::cout << ((int) array[pointer_array]) << ' ';
		} else if(input[i] == ','){
			std::cin >> array[pointer_array];
		} else if(input[i] == '['){
			s.push(pointer_array);
		} else if(input[i] == ']'){
			if(s.empty()){
				error();
			}
			if(array[pointer_array] != 0){
				i = s.top();
			} else {
				s.pop();
			}
		} else {
			// error();
		}
	}
}