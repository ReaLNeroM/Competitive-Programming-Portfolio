#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int _x = 0; _x < t; _x++){
		int y, x;
		std::cin >> y >> x;

		if(y > x){
			std::swap(y, x);
		}

		std::cout << 2 * y - 2 << '\n';
	}
}