#include <bits/stdc++.h>

const int maxn = 1e6 + 1e2;
std::vector<std::pair<int, int> > adj[maxn];
int dp[maxn][2];
int dp2[maxn][2];
int order[maxn], order_par[maxn], order_dist[maxn];
 
int main(){ 
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp2[i][0] = 2e9;
		dp2[i][1] = 2e9;
	}
 
	for(int i = 0; i < n - 1; i++){
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		a--, b--;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
 
	int root = -1;
	for(int i = 0; i < n; i++){
		if(adj[i].size() != 1){
			root = i;
			break;
		}
	}
	
	if(n == 2){
		printf("1 0");
		fflush(stdout);
		return 0;
	}

	order[0] = root, order_par[0] = -1, order_dist[0] = 0;
	int curr_ite = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < adj[order[i]].size(); j++){
			if(adj[order[i]][j].first != order_par[i]){
				order[curr_ite] = adj[order[i]][j].first;
				order_par[curr_ite] = order[i];
				order_dist[curr_ite] = adj[order[i]][j].second;
				curr_ite++;
			}
		}
	}

	for(int i = n - 1; i >= 1; i--){
		int pos = order[i], par = order_par[i], dist = order_dist[i];
		int get = dp[pos][0] + dist;

		if(dp[par][0] < get){
			dp[par][1] = dp[par][0];
			dp[par][0] = get;
		} else if(dp[par][1] < get){
			dp[par][1] = get;
		}

		if(adj[pos].size() == 1){
			dp2[pos][0] = 0;
		}
		get = dp2[pos][0] + dist;

		if(get < dp2[par][0]){
			dp2[par][1] = dp2[par][0];
			dp2[par][0] = get;
		} else if(get < dp2[par][1]){
			dp2[par][1] = get;
		}
	}

	for(int i = 1; i < n; i++){
		int pos = order[i], par = order_par[i], dist = order_dist[i];

		int get = dp[par][0];
 
		if(get == dp[pos][0] + dist){
			get = dp[par][1] + dist;
		} else {
			get += dist;
		}
 
		if(dp[pos][0] < get){
			dp[pos][1] = dp[pos][0];
			dp[pos][0] = get;
		} else if(dp[pos][1] < get){
			dp[pos][1] = get;
		}

		get = dp2[par][0];
 
		if(get == dp2[pos][0] + dist){
			get = dp2[par][1] + dist;
		} else {
			get += dist;
		}
 
		if(get < dp2[pos][0]){
			dp2[pos][1] = dp2[pos][0];
			dp2[pos][0] = get;
		} else if(get < dp2[pos][1]){
			dp2[pos][1] = get;
		}
	}
 
	int bestid = 0;
	for(int i = 0; i < n; i++){
		if(adj[i].size() == 1){
			if(dp2[i][1] != 2e9){
				dp2[i][0] = dp2[i][1];
			}
		}
		if(dp[i][0] - dp2[i][0] < dp[bestid][0] - dp2[bestid][0]){
			bestid = i;
		}
	}
	
	printf("%d %d\n", bestid + 1, dp[bestid][0] - dp2[bestid][0]);
}