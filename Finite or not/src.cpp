#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++){
		ll ll_p, ll_q, ll_b;
		std::cin >> ll_p >> ll_q >> ll_b;
		__int128 p = ll_p, q = ll_q, b = ll_b;

		bool infinite = false;
		for(int j = 0; j < 100; j++){
			if(j == 99){
				infinite = true;
			}

			p = (p % q) * b;

			if(p == 0){
				break;
			}
		}

		if(infinite){
			std::cout << "Infinite" << '\n';
		} else {
			std::cout << "Finite" << '\n';
		}
	}
}