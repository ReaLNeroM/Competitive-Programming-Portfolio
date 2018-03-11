#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	ll n, q;
	std::cin >> n >> q;

	for(int i = 0; i < q; i++){
		ll ind;
		std::cin >> ind;

		while(ind % 2 == 0){
			ind += n - ind / 2;
		}

		ll res = ind / 2 + ind % 2;
		std::cout << res << '\n';
	}
}