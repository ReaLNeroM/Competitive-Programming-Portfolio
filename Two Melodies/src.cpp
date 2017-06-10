#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 5005;
ll n;
ll dp[maxn][maxn];
ll next[maxn][3][2];
std::map<ll, ll> m;
std::map<ll, ll> old;
ll val[maxn];
ll board[maxn];
ll boardold[maxn];

ll dfs(ll a, ll b){
	if(a > b){
		std::swap(a, b);
	}

	if(dp[a][b] == -1){
		dp[a][b] = 0;

		if(a != n){
			for(ll i = 0; i < 3; i++){
				if(b == n or next[a][i][0] != b){
					dp[a][b] = std::max(dp[a][b], dfs(next[a][i][0], b) + 1);
				} 
				if(b == n or next[a][i][1] != b){
					dp[a][b] = std::max(dp[a][b], dfs(next[a][i][1], b) + 1);
				}
			}

			dp[a][b] = std::max(dp[a][b], dfs(n, b) + 1);
		}
	}

	return dp[a][b];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(ll i = 0; i < 7; i++){
		board[i] = n;
		boardold[i] = n;
	}

	for(ll i = n - 1; i >= 0; i--){
		if(m.find(val[i] + 1) == m.end()){
			next[i][0][0] = n;
		} else {
			next[i][0][0] = m[val[i] + 1];
		}
		if(old.find(val[i] + 1) == old.end()){
			next[i][0][1] = n;
		} else {
			next[i][0][1] = old[val[i] + 1];
		}
		if(m.find(val[i] - 1) == m.end()){
			next[i][2][0] = n;
		} else {
			next[i][2][0] = m[val[i] - 1];
		}
		if(old.find(val[i] - 1) == old.end()){
			next[i][2][1] = n;
		} else {
			next[i][2][1] = old[val[i] - 1];
		}
		next[i][1][0] = board[val[i] % 7];
		next[i][1][1] = boardold[val[i] % 7];

		if(m.find(val[i]) != m.end()){
			old[val[i]] = m[val[i]];
		}

		m[val[i]] = i;
		boardold[val[i] % 7] = board[val[i] % 7];
		board[val[i] % 7] = i;
	}

	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			dp[i][j] = -1;
		}
	}

	ll res = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j < n; j++){
			res = std::max(res, dfs(i, j));
		}
	}

	std::cout << res << std::endl;
}