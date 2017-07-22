#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll height[maxn];
ll recharge[maxn];
ll dp[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	ll trees;
	std::cin >> trees;
	
	for(ll i = 0; i < trees; i++){
		std::cin >> height[i];
	}
	for(ll i = 0; i < trees; i++){
		std::cin >> recharge[i];
	}
	
	dp[0] = 0;
	
	std::deque<std::vector<ll>> v;
	v.push_back({dp[0], recharge[0]});
	
	ll curr_pivot = 0;
	
	for(ll i = 1; i < trees; i++){
		dp[i] = 1e18;
		
		curr_pivot = std::min(curr_pivot, (ll) v.size() - 1);
		while(curr_pivot + 1 < v.size() and v[curr_pivot][0] + v[curr_pivot][1] * height[i] >= v[curr_pivot + 1][0] + v[curr_pivot + 1][1] * height[i]){
			curr_pivot++;
		}	
		
		dp[i] = v[curr_pivot][0] + height[i] * v[curr_pivot][1];
		
		v.push_back({dp[i], recharge[i]});
		
		while(v.size() >= 3 and (v[v.size() - 3][0] - v[v.size() - 1][0]) / (v[v.size() - 1][1] - v[v.size() - 3][1]) <= (v[v.size() - 3][0] - v[v.size() - 2][0]) / (v[v.size() - 2][1] - v[v.size() - 3][1])){
			v[v.size() - 2] = v[v.size() - 1];
			v.pop_back();
		}
		// for(ll j = 0; j < i; j++){
		// 	dp[i] = std::min(dp[i], dp[j] + height[i] * recharge[j]);
		// }
	}
	
	std::cout << dp[trees - 1] << std::endl;
}