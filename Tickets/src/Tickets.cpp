#include <iostream>

typedef long long ll;

int main() {
	ll divisions, index;
	std::cin >> divisions >> index;

	index--;

	std::string code = "";

	ll invert = 0;

	for(ll pos = (ll) 1 << (divisions - 1); pos > 0; pos /= 2){
		if(pos <= index){
			index -= pos;
			code += '1' - invert;
			invert = 2;
		} else {
			code += '0' + invert;
		}

		if(invert >= 1){
			invert--;
		}
	}

	std::cout << code;
	return 0;
}
