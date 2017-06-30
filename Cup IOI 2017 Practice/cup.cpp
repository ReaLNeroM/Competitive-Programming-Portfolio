#include "cup.h"
#include <iostream>

std::vector<int> find_cup() {
	char c;
	int a, b;
    std::vector<int> result;
	while(true){
		std::cin >> c >> a >> b;
		if(c == 'a'){
		    result = {a, b};
		    break;
		} else {
			std::cout << ask_shahrasb(a, b) << std::endl;
		}
	}

    return result;
}
