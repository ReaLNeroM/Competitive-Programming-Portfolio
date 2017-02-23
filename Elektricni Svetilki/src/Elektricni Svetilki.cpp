#include <iostream>

std::string svetilki;

void change(int start, int iter) {
	if(start >= svetilki.length()){
		return;
	}

	if(svetilki[start] == 'N'){
		svetilki[start] = 'Y';
	} else{
		svetilki[start] = 'N';
	}

	change(start + iter, iter);
}

int main() {

	std::cin >> svetilki;

	int result = 0;
	for(int i = 0; i < svetilki.length(); i++){
		if(svetilki[i] == 'Y'){
			change(i, i + 1);
			result++;
		}
	}

	std::cout << result;
	return 0;
}
