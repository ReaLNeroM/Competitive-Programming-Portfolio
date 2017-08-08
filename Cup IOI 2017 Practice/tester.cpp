#include "cup.h"
#include <iostream>

std::vector<int> find_cup() {
	char c;
	int a, b;
    std::vector<int> result;
    int orig = ask_shahrasb(0, 0);
    std::cout << orig << std::endl;
	while(true){
		std::cin >> c >> a >> b;
		if(c == 'a'){
		    result = {a, b};
		    break;
		} else {
			int res = ask_shahrasb(a, b);
			std::cout << res << ' ';
			std::cout << (orig ^ res);

			std::cout << std::endl;
		}
	}

    return result;
}