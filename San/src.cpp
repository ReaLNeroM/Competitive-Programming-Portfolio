#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 50;
ll h[maxn];
ll gold[maxn];
ll n, k;

ll ways(ll pos, ll last, ll accumulated){
	if(pos == n){
		return (accumulated >= k);
	}

	ll sum = 0;

	if(last == -1 or h[last] <= h[pos]){
		sum += ways(pos + 1, pos, accumulated + gold[pos]);
	}
	sum += ways(pos + 1, last, accumulated);

	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> h[i] >> gold[i];
	}

	std::cout << ways(0, -1, 0);
}