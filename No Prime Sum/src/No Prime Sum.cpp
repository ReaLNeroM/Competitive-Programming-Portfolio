#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 4005;
int val[maxn];
int used[maxn];
int match[maxn];
int comp[200005];
vector<int> adj[maxn];
ll res = 0;

int dfs(int pos){
	if(used[pos]){
		return 0;
	}
	used[pos] = true;

	for(int i = 0; i < adj[pos].size(); i++){
		if(match[adj[pos][i]] == -1 or dfs(match[adj[pos][i]])){
			match[adj[pos][i]] = pos;
			match[pos] = adj[pos][i];
			return 1;
		}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);

	comp[1] = true;
	for(int i = 1; i <= 200000; i++){
		if(!comp[i] and i <= 10000){
			for(int j = i * i; j <= 200000; j += i){
				comp[j] = true;
			}
		}
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(!comp[val[i] + val[j]]){
				adj[i].push_back(2000 + j);
				adj[j].push_back(2000 + i);
			}
		}
	}

	fill(match, match + maxn, -1);
	for(int i = 0; i < n; i++){
		if(match[i] == -1){
			fill(used, used + maxn, false);
			res += dfs(i);
		}
	}

	cout << n - res;
}
