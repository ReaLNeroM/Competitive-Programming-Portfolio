#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e5 + 1e2;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n;
	std::cin >> n;
	
	ll whole_sum = 0;
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		whole_sum += val[i];
	}
	
	ll sum = 0;
	ll best = 1e18;
	
	for(ll i = 0; i < n - 1; i++){
		sum += val[i];
		whole_sum -= val[i];
		best = std::min(best, std::abs(sum - whole_sum));
	}
	
	std::cout << best;
}