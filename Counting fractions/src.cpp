#include <bits/stdc++.h>

typedef long long ll;

int main(){
	ll res = 8LL * 9LL / 2LL;
	for(int i = 2; i <= 8; i++){
		for(int j = i; j <= 8; j += i){
			std::cout << i << ' ' << j << '\n';
			res -= 1;
		}
	}
	std::cout << res << '\n';
}