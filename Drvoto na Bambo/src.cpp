#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 100005;
const ll mod = 1e9 + 7;
int edg[maxn];
int dp[maxn][2];
std::vector<int> adj[maxn];
std::vector<int> pref[maxn][2];
std::vector<int> suf[maxn][2];
int sub[maxn];
int order[maxn];
int step = 0;

void dfs(int pos, int par){
	order[step] = pos;
	step++;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs(adj[pos][i], pos);
			sub[pos] |= sub[adj[pos][i]];
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 1; i < n; i++){
		std::cin >> edg[i];
		adj[i].push_back(edg[i]);
		adj[edg[i]].push_back(i);
	}

	for(int i = 0; i < n; i++){
		std::cin >> sub[i];

		pref[i][0].resize(adj[i].size() + 5);
		suf[i][0].resize(adj[i].size() + 5);
		pref[i][1].resize(adj[i].size() + 5);
		suf[i][1].resize(adj[i].size() + 5);
	}

	dfs(0, -1);

	for(int pos = n - 1; pos >= 0; pos--){
		for(int above = 0; above < 2; above++){
			dp[pos][above] = 1;

			if(above){
				ll get = 1;
				pref[pos][above][0] = 1;
				suf[pos][above][adj[pos].size() + 1] = 1;

				for(int i = 0; i < adj[pos].size(); i++){
					if(adj[pos][i] != par){
						get *= dp[adj[pos][i]][true];
						
						//pref
						//suf
					}
				}

				dp[pos][above] = get;

				for(int i = 1; i <= adj[pos].size(); i++){
					pref[pos][above][i] *= pref[pos][above][i - 1];
					pref[pos][above][i] %= mod;
				}

				for(int i = adj[pos].size(); i >= 1; i--){
					suf[pos][above][i] *= suf[pos][above][i + 1];
					suf[pos][above][i] %= mod;
				}

				for(int i = 0; i < adj[pos].size(); i++){
					if(adj[pos][i] != par){
						dp[pos][above] += pref[pos][above][i] * suf[pos][above][i + 2] * dp_dfs(adj[pos][i], pos, true);
					}
				}
			} else {
				for(int i = 0; i < adj[pos].size(); i++){
					if(adj[pos][i] != par){
						dp[pos][above] *= 2 * dp[adj[pos][i]][false];
						dp[pos][above] %= mod;
					}
				}
			}

		}
	}

	std::cout << dp[0][0];
}