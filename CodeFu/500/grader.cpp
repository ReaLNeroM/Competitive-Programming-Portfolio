#include "CodeFu.cpp"
#include <iostream>

typedef long long ll;

int main(){
	DefendTheHouse x;
	auto res = x.minimumCost(
2, 2, {"4;2;2;1;4","2;3;5;0;0","3;4;1;0;0","4;0;0;0;0","4;0;0;0;0"});
  	std::cout << res << '\n';
}
