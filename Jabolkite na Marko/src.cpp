#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::cout << (4 - n % 4) % 4 * 9;
}