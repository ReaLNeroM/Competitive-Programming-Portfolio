#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll maxbit = (1 << 17);
const ll INF = 1e15;

ll calc(ll a, ll start, ll n){
	ll res = 0;
	ll x = 1;
	for(ll i = start, j = n - 1 - start; i <= j; i++, j--){
		x *= a;

		if(res > INF or x > INF){
			return INF;
		}

		if(i == j){
			res += x;
		} else {
			res += 2 * x;
		}
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		ll l, n, k;
		std::cin >> l >> n >> k;

		int res = 0;
		bool exceed = false;

		for(int i = 0; i < n / 2 + n % 2; i++){
			if(i != 0){
				if(k == 0){
					res = 2 * i;
					break;
				}
				if(k <= 1){
					res = 2 * i + 1;
					break;
				}
				k -= 2;
			} else {
				k -= 1;
			}

			exceed = true;
			int currBlock = calc(l, i + 1, n) + 1;
			if(2 * (i + 1) <= n){
				currBlock++;
			}

			for(int j = 0; j < l; j++){
				if(k < currBlock){
					exceed = false;
					break;
				} else {
					k -= currBlock;
				}
			}

			if(exceed){
				res = n;
				break;
			}
		}

		if(k % 2 == 1 and !exceed){
			res++;
		}
		std::cout << "Case #" << testcase << ": ";

		std::cout << n - res << '\n';
	}
}
