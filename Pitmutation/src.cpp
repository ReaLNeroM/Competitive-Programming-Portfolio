#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 305;
ll dp[maxn][maxn + maxn];
std::vector<ll> val[2];
ll res = 0;
ll n, s;

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n >> s;
	
	for(ll i = 0; i < 2; i++){
		val[i].resize(n);
		for(ll j = 0; j < n; j++){
			std::cin >> val[i][j];
		}
	}

	std::sort(val[0].begin(), val[0].end(), std::greater<ll>());
	std::sort(val[1].begin(), val[1].end());

	std::cout << dfs(0, 0);
}