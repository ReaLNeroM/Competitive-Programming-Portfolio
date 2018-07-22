#include "catdog.h"

const int maxn = 1e5 + 1e2;
int x;
std::vector<int> adj[maxn];
int cats[maxn];
int cats_node[maxn];
int dogs[maxn];
int dogs_node[maxn];
int dp[maxn][2];
int par[maxn];

void dfs0(int pos){
	for(int next : adj[pos]){
		if(next != par[pos]){
			par[next] = pos;
			dfs0(next);
		}
	}
}

void dfs(int pos){
	cats[pos] = cats_node[pos];
	dogs[pos] = dogs_node[pos];

	dp[pos][0] = dp[pos][1] = 0;

	for(int next : adj[pos]){
		if(next != par[pos]){
			dfs(next);
			cats[pos] |= cats[next];
			dogs[pos] |= dogs[next];

			if(dogs[next] and cats[next]){
				dp[pos][0] += std::min(dp[next][0], dp[next][1] + 1);
				dp[pos][1] += std::min(dp[next][1], dp[next][0] + 1);
			} else if(cats[next]){
				dp[pos][1] += 1;
			} else if(dogs[next]){
				dp[pos][0] += 1;
			}
		}
	}

	if(dogs_node[pos]){
		dp[pos][0] = maxn;
	}
	if(cats_node[pos]){
		dp[pos][1] = maxn;
	}
}

void initialize(int N, std::vector<int> A, std::vector<int> B) {
	x = A.size();
	for(int i = 0; i < x; i++){
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	par[1] = -1;
	dfs0(1);
}

int cat(int v) {
	cats_node[v] = true;
	int pos = v;
	while(pos != -1){

	}

	return std::min(dp[1][0], dp[1][1]);
}

int dog(int v) {
	dogs_node[v] = true;
	dfs(1);
	
	return std::min(dp[1][0], dp[1][1]);
}

int neighbor(int v) {
	cats_node[v] = dogs_node[v] = false;
	dfs(1);

	return std::min(dp[1][0], dp[1][1]);
}
