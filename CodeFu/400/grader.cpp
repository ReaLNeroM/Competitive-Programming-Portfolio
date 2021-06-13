#include "CodeFu.cpp"
#include <iostream>

typedef long long ll;

int main(){
	RubiksCube x;
	auto res = x.solve("UDU'FRF'LRBUF'B'URLR'BUF'L'D'");
	std::cout << res << '\n';
}
