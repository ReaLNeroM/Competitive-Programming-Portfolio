#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 17;
const ll maxn_pow = (1LL << maxn);
ll query[maxn_pow][maxn];
ll parity[maxn_pow];
ll dpxor[maxn][maxn_pow]; //residue of A if smaller than bitset B
ll n, q;
ll fullset;

ll dfsxor(ll pos, ll bitset){
	if(dpxor[pos][bitset] == -1){
		ll& ans = dpxor[pos][bitset];
		ans = 0;

		if((parity[fullset ^ bitset] & (1 << pos)) == 0){
			if(bitset == 0){
				ans = 1;
			} else {
				for(ll i = 0; i < n; i++){
					if(i != pos and ((1 << i) & bitset)){
						ans += dfsxor(i, bitset ^ (1 << i));
					}
				}
			}
		}
	}

	return dpxor[pos][bitset];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> q;
	fullset = (1 << n) - 1;

	for(ll i = 0; i < q; i++){
		std::stringstream str;

		std::string val;
		std::cin >> val;

		str << val;

		ll bitset = 0;
		for(ll j = 0; j < n; j++){
			bitset *= 2;
			bitset += val[j] - '0';
		}

		parity[bitset] = bitset;
	}


	for(ll i = 1; i < (1 << n); i++){
		for(ll j = 1; j < (1 << n); j *= 2){
			if((i & j) == 0){
				for(ll k = 1; k < j; k *= 2){
					if((i & k) == 0 and j != k){
						parity[i ^ j ^ k] ^= parity[i];
					}
				}
				
				parity[i ^ j] ^= parity[i];
			}
		}
	}
// 	for(ll i = fullset; i >= 1; i--){
// 		for(ll j = i + 1; j < (1 << n); j++){
// 			if((i & j) == i){
// 				parity[j] ^= parity[i];
// 			}
// 		}
// 	}

	std::memset(dpxor, -1, sizeof(dpxor));

	ll res = 0;

	for(ll i = 0; i < n; i++){
		if(parity[(1 << i)] & (1 << i)){
			parity[(1 << i)] ^= (1 << i);
			res += dfsxor(i, fullset ^ (1 << i));
			parity[(1 << i)] ^= (1 << i);
		}
	}

	std::cout << res << '\n';
}
