#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1000;
ll val[maxn];
ll repair[maxn];
static ll dist[maxn][maxn];
static ll actualdist[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll v, e, r, d;
	std::cin >> v >> e >> r >> d;

	r++;
	repair[0] = 0;

	r++;
	repair[r - 1] = v - 1;

	for(ll i = 1; i < r - 1; i++){
		std::cin >> repair[i];
		repair[i]--;
	}

	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			dist[i][j] = d + 1;
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < r; j++){
			actualdist[i][j] = v * d + v;
		}
	}

	for(ll i = 0; i < e; i++){
		ll f, s, c;
		std::cin >> f >> s >> c;
		f--, s--;

		dist[f][s] = std::min(dist[f][s], c);
		dist[s][f] = std::min(dist[s][f], c);
	}

	for(int k = 0; k < v; k++){
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < r; j++){
			if(dist[repair[i]][repair[j]] <= d){
				actualdist[i][j] = dist[repair[i]][repair[j]];
			}
		}
	}

	for(int k = 0; k < r; k++){
		for(int i = 0; i < r; i++){
			for(int j = 0; j < r; j++){
				actualdist[i][j] = std::min(actualdist[i][j], actualdist[i][k] + actualdist[k][j]);
			}
		}
	}

	if(actualdist[0][r - 1] >= v * d + v){
		std::cout << "stuck\n";
	} else {
		std::cout << actualdist[0][r - 1] << '\n';
	}
}