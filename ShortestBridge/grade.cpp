#include <bits/stdc++.h>
#include "src.cpp"

int main(){
	std::vector<std::vector<int>> v(5);
	v[0] = {1, 1, 1, 1, 1};
	v[1] = {1, 0, 0, 0, 1};
	v[2] = {1, 0, 1, 0, 1};
	v[3] = {1, 0, 0, 0, 1};
	v[4] = {1, 1, 1, 1, 1};

	Solution x;
	std::cout << x.shortestBridge(v);
}