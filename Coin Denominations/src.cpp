#include <bits/stdc++.h>

typedef long long ll;

const __int128_t maxprecompute = 1e6;
const __int128_t INF = 1e30;
const __int128_t mod = 1e9 + 7;
const __int128_t maxcoin = 1e2 + 1e2;
__int128_t precompute[maxprecompute + 500];
ll conv_value[maxcoin];
ll conv_weight[maxcoin];
__int128_t value[maxcoin];
__int128_t weight[maxcoin];
ll coins, maxvalue, queries;

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> coins >> maxvalue >> queries;
	for(ll i = 0; i < coins; i++){
		std::cin >> conv_value[i] >> conv_weight[i];
		value[i] = conv_value[i];
		weight[i] = conv_weight[i];
	}

	precompute[0] = 0;
	for(__int128_t i = 1; i < maxprecompute + 500; i++){
		precompute[i] = INF;
		for(__int128_t j = 0; j < coins; j++){
			if(i >= value[j]){
				precompute[i] = std::min(precompute[i], precompute[i - value[j]] + weight[j]);
			}
		}
	}

	for(ll i = 0; i < queries; i++){
		ll conv_q;
		std::cin >> conv_q;
		__int128_t q = conv_q;

		__int128_t res = INF;
		if(q >= maxprecompute){
			for(ll j = 0; j < coins; j++){
				//try to take this dude as much as you can:

				// q - value[j] * k < maxprecompute
				// q - maxprecompute < value[j] * k
				// (q - maxprecompute) / value[j] < k

				__int128_t taken = (q - maxprecompute + value[j]) / value[j];
				__int128_t remainder = q - taken * value[j];

				if(precompute[remainder] != INF){
					res = std::min(res, taken * weight[j] + precompute[remainder]);
				}
			}
		} else {
			res = precompute[q];
		}

		if(res == INF){
			res = -1;
		} else {
			res %= mod;
		}

		ll conv_res = res;

		std::cout << conv_res << '\n';
	}
}
