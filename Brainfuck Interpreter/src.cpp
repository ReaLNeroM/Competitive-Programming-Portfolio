#include <iostream>
#include <stack>
#include <string>
#include <deque>
#include <stdlib.h>

void error(std::string error){
	std::cerr << "ERROR: " << error << std::endl;
	exit(EXIT_FAILURE);
}

int main(){
	std::string input;
	std::cin >> input;

	std::stack<int> bracket_indices;

	std::deque<char> array(1);

	int tape_head = 0;

	for(int i = 0; i < (int) input.size(); i++){
		if(input[i] == '+'){
			array[tape_head]++;
		} else if(input[i] == '-'){
			array[tape_head]--;
		} else if(input[i] == '<'){
			tape_head--;
			if(tape_head == -1){
				array.push_front(0);
				tape_head++;
			}
		} else if(input[i] == '>'){
			tape_head++;
			if(tape_head == (int) array.size()){
				array.push_back(0);
			}
		} else if(input[i] == '.'){
			std::cout << ((char) array[tape_head]);
		} else if(input[i] == ','){
			std::cin >> array[tape_head];
		} else if(input[i] == '['){
			if(array[tape_head] == 0){
				int open_count = 0;

				int j = i; // stored for error logging.
				do {
					open_count += (input[i] == '[');
					open_count -= (input[i] == ']');
					i++;
				} while(i < (int) input.size() and open_count > 0);
				i--; // to cancel out iteration increment

				if(open_count > 0){
					error("Couldn't find matching closing bracket for bracket at " + std::to_string(j));
				}
			} else {
				bracket_indices.push(i);
			}
		} else if(input[i] == ']'){
			if(bracket_indices.empty()){
				error("Found closing bracket at " + std::to_string(i) + " without a matching opening bracket");
			}

			if(array[tape_head] != 0){
				i = bracket_indices.top();
			} else {
				bracket_indices.pop();
			}
		} else {
			//ignore comments.
		}
	}
}
