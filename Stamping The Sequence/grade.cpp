#include <bits/stdc++.h>
#include "src.cpp"

int main(){
	Solution x;
	auto xx = x.movesToStamp("de", "ddeddeddee");
	for(int i : xx){
		std::cout << i << ' ';
	}
}