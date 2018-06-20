#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 3e5 + 1e2;
std::vector<int> adj[maxn];
int paths[maxn][6][32];
int color[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, m, k;
	std::cin >> n >> m >> k;
	ll k_bitset = (1 << k);

	for(int i = 0; i < n; i++){
		std::cin >> color[i];
		color[i]--;
	}

	ll res = 0;

	for(ll i = 0; i < m; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;
		if(color[f] == color[s]){
			continue;
		}

		adj[f].push_back(s);
		adj[s].push_back(f);

		//sum k == 2
		res += 2;

		paths[f][2][(1 << color[f]) | (1 << color[s])]++;
		paths[s][2][(1 << color[f]) | (1 << color[s])]++;
	}

	for(int curr_k = 3; curr_k <= k; curr_k++){
		for(int i = 0; i < n; i++){
			for(int j : adj[i]){
				for(int l = 0; l < k_bitset; l++){
					if(!(l & (1 << color[i]))){
						paths[i][curr_k][(l | (1 << color[i]))] += paths[j][curr_k - 1][l];
						res += paths[j][curr_k - 1][l];
					}
				}
			}
		}
	}

	std::cout << res << '\n';
}