#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;

	ll bfound = 0;
	ll moves = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		if(s[i] == 'b'){
			bfound++;
		} else if(s[i] == 'a'){
			moves += bfound;
			moves %= mod;
			bfound += bfound;
			bfound %= mod;
		}
	}

	std::cout << moves;
}