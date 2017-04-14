#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int val[maxn];
vector<int> adj[maxn];
int besta = -100, bestb = -100;
pair<int, int> dp[maxn];

pair<int, int> dfs(int pos){
	if(dp[pos] == make_pair(-1, -1)){
		if(adj[pos].empty()){
			dp[pos] = {0, 0};
		} else {
			pair<int, int> res = {0, maxn};
			for(int i = 0; i < adj[pos].size(); i++){
				int nnext = adj[pos][i];

				auto get = dfs(nnext);

				if(get.first == 1 and res.first != 1){
					res.second = min(res.second, get.second + 1);
				} else if(get.first == 0){
					if(res.first != 1){
						res.second = -maxn;
					}
					res.first = 1;
					res.second = max(res.second, get.second + 1);
				}
			}

			dp[pos] = res;
		}
	}

	return dp[pos];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int v, e, k;
	cin >> v >> e >> k;

	for(int i = 0; i < k; i++){
		int ind;
		cin >> ind;
		val[ind - 1]++;
	}
	
	for(int i = 0; i < v; i++){
		dp[i] = {-1, -1};
	}

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;
		adj[f].push_back(s);
	}
	
	for(int i = 0; i < v; i++){
		if(val[i]){
			auto get = dfs(i);
			if(get.first == 0){
				bestb = max(bestb, get.second);
			} else {
				besta = max(besta, get.second);
			}
		}
	}
	
	if(besta > bestb){
		cout << "A";
	} else {
		cout << "B";
	}
}
