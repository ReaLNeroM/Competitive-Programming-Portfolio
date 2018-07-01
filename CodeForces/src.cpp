#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll start = 1;
	ll end = 100000;
	ll last = 0;
	ll res[2][50 * (end + 50) + 1];
	ll abit = 0;
	ll bbit = 1;
	res[abit][1]++;
	for(ll n = start; n <= end; n++){
		if(n % 1024 == 0){
			std::cout << n << std::endl;
		}

		ll sum = 0;
		for(ll j = n - 1; j <= 50 * n; j++){
			if(res[abit][j]){
				if(!res[bbit][j + 1]){
					res[bbit][j + 1] = true;
					sum++;
				}
				if(!res[bbit][j + 5]){
					res[bbit][j + 5] = true;
					sum++;
				}
				if(!res[bbit][j + 10]){
					res[bbit][j + 10] = true;
					sum++;
				}
				if(!res[bbit][j + 50]){
					res[bbit][j + 50] = true;
					sum++;
				}
				res[abit][j] = false;
			}
		}
		abit ^= 1;
		bbit ^= 1;

		if(sum - last != 49 and n != start){
			std::cout << n << ' ' << sum << ' ' << sum - last << std::endl;
			std::cout << "ERRRRRR" << std::endl;
		}
		last = sum;
	}
}