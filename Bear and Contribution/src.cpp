#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int val[maxn];
int sec[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	int n, k, t5, t1;
	std::cin >> n >> k >> t5 >> t1;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}
	std::sort(val, val + n);
	
	std::copy(val, val + n, sec);

	ll res = 1e18;

	if(5 * t1 <= t5){
		ll curr = 0;

		for(int i = 0; i < n; i++){
			if(i >= k){
				curr -= val[i - k];
			}
			curr += val[i];

			if(i >= k - 1){
				res = std::min(res, (k * val[i] - curr) * t1);
			}
		}
	} else {
		for(int x = 1; x < 2; x++){
			ll curr = 0
;	x
			std::copy(sec, sec + n, val);

			for(int i = 0; i < n; i++){
				if(val[i] % 5 <= x){
					curr += (x - val[i] % 5) * t1;
					val[i] += (x - val[i] % 5);
				} else {
					curr += (x + (5 - val[i] % 5) % 5) * t1;
					val[i] += (x + (5 - val[i] % 5) % 5);
				}

				val[i] /= 5;
			}

			for(int i = 0; i < n; i++){
				if(i >= k){
					curr -= val[i - k];
				}
				curr += val[i];

				std::cout << curr << ' ';
				if(i >= k - 1){
					res = std::min(res, (k * val[i] - curr) * t5);
				}
			}
		}
	}

	std::cout << res << std::endl;
}
