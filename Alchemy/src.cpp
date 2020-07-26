#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cout << "Case #" << testcase << ": ";

		int n;
		std::cin >> n;

		std::string s;
		std::cin >> s;

		int difference = 0;
		for(auto i : s){
			difference += (i == 'B') ? 1 : -1;
		}


		if(difference != -1 and difference != 1){
			std::cout << 'N';
		} else {
			std::cout << 'Y';
		}

		std::cout << '\n';
	}
}