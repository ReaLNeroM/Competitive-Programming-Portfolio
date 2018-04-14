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

		if((parity[(1 << n) & (fullset ^ bitset)] & (1 << pos)) == 0){
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

ll get_biggest(ll bitset){
	for(ll j = 1; j <= bitset; j *= 2){
		if(j * 2 > bitset){
			return j;
		}
	}

	return -1;
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

		ll biggest_bit = get_biggest(bitset);

		parity[(biggest_bit * 2) | bitset] = bitset;
	}


	for(ll bitset = 2; bitset < (1 << n); bitset++){
		ll biggest_bit = get_biggest(bitset);
		parity[ bitset                | (biggest_bit * 2)] ^= parity[bitset];
		parity[(bitset ^ biggest_bit) | (biggest_bit * 2)] ^= parity[bitset];
	}

	for(int i = 0; i < (1 << (n + 1)); i++){
		int generated_bitset = 0;
		for(int pow10 = 1, bit = 1; bit <= i; pow10 *= 10, bit *= 2){
			if(i & bit){
				generated_bitset += pow10;
			}
		}
		std::cout << generated_bitset << ' ' << parity[i] << '\n';
	}
	std::memset(dpxor, -1, sizeof(dpxor));

	ll res = 0;////////////

	for(ll i = 0; i < n; i++){
		if(parity[(1 << i)] & (1 << i)){
			parity[(1 << i)] ^= (1 << i);
			res += dfsxor(i, fullset ^ (1 << i));
			parity[(1 << i)] ^= (1 << i);
		}
	}

	std::cout << res << '\n';
}
