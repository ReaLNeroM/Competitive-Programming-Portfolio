#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1005;
const int maxinterval = 5005;

int val[maxn][maxn];
int x[maxn][maxn];
int y[maxn][maxn];
int ordy = 0, ordx = 0;

bool used[maxinterval][maxinterval];
int pair_v[maxinterval];
int pair_u[maxinterval];
int dist[maxinterval];
std::vector<int> adj[maxinterval];

bool bfs(){
	std::queue<int> q;

	for(int i = 0; i < ordx; i++){
		if(pair_u[i] == ordy){
			dist[i] = 0;
			q.push(i);
		} else {
			dist[i] = 1e9;
		}
	}

	dist[ordx] = 1e9;

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		if(fr == ordx){
			return true;
		}

		for(int i : adj[fr]){
			int pair = pair_v[i];

			if(dist[pair] == 1e9){
				dist[pair] = dist[fr] + 1;
				q.push(pair);
			}
		}
	}

	return false;
}

int dfs(int pos){
	if(pos == ordx){
		return true;
	}

	for(int i : adj[pos]){
		int pair = pair_v[i];

		if(dist[pair] == dist[pos] + 1 and dfs(pair)){
			pair_u[pos] = i;
			pair_v[i] = pos;
			return true;
		}
	}

	dist[pos] = 1e9;

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, rook;
	std::cin >> n >> rook;

	for(int i = 0; i < rook; i++){
		int py, px;
		std::cin >> py >> px;

		val[py - 1][px - 1] = true;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			x[i][j] = ordx;

			if(val[i][j]){
				ordx++;
			}
		}
		ordx++;
	}

	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++){
			y[i][j] = ordy;

			if(val[i][j]){
				ordy++;
			}
		}
		ordy++;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!val[i][j]){
				adj[x[i][j]].emplace_back(y[i][j]);
			}
		}
	}

	for(int i = 0; i < ordx; i++){
		pair_u[i] = ordy;
	}
	for(int i = 0; i < ordy; i++){
		pair_v[i] = ordx;
	}

	int res = 0;

	while(bfs()){
		for(int i = 0; i < ordx; i++){
			if(pair_u[i] == ordy and dfs(i)){
				res++;
			}
		}
	}

	std::cout << res << '\n';

	for(int i = 0; i < ordx; i++){
		used[i][pair_u[i]] = true;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!val[i][j] and used[x[i][j]][y[i][j]]){
				std::cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}
}
