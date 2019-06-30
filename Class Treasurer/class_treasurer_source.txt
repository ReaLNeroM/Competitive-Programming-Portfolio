#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll mod = 1e9 + 7;
ll pow2[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	pow2[0] = 2;
	for(ll i = 1; i < maxn; i++){
		pow2[i] = (pow2[i - 1] * 2LL) % mod;
	}

	for(ll testCase = 1; testCase <= testCases; testCase++){
		ll n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;

		ll res = 0;
		int running = 0;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == 'B'){
				running++;
			} else {
				running--;
			}
			if(running > k){
				s[i] = 'A';
				running -= 2;
				res += pow2[i];
				res %= mod;
			}
			running = std::max(running, 0);
		}

		std::cout << "Case #" << testCase << ": " << res << std::endl;
	}
}