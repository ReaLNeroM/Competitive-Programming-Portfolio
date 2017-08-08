#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int maxh = 1e6;
int height[maxn];
int cost[maxn];
std::map<std::vector<int> > m;

std::vector<int> query(int pos){
	return m.lower_bound(pos);	
}

void add(int b, int a){
	int l = 0, r = maxh;
	int least = maxh + 1;
	
	while(l <= r){
		int mid = (l + r) / 2;
		
		auto midv = m.lower_bound(mid);
		
		if(mid)
	}

	l = 0, r = maxh;
	int most = -1;
	
	while(l <= r){
		int mid = (l + r) / 2;
	}
	
	if(least <= most){
		auto ite = m.lower_bound(least);
		auto site = ite;
		site++;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;	
	
	for(int i = 0; i < n; i++){
		std::cin >> height[i];
	}
	
	ll sum = 0;
	for(int i = 0; i < n; i++){
		std::cin >> cost[i];
		sum += cost[i];
		cost[i] *= -1;
	}
	dp[0] = 0;
	
	m[maxh] = {0, height[i]};
	for(int i = 1; i < n; i++){
		auto x = query(-2 * height[i]);
		dp[i] = x[0] - x[1] * height[i] * 2 + height[i] * height[i] + cost[i];
		add(dp[i] + height[i] * height[i], height[i]);
	}
	std::cout << sum + dp[n - 1] << '\n';
}