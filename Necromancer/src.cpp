#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1005;
int votable[maxn];
std::vector<int> adj[maxn];
int parent[maxn][maxn];
bool used[maxn];
int mid;
int res = maxn;

bool dfs(int pos){
	if(used[pos]){
		return false;
	}

	used[pos] = true;

	for(int i = 0; i < adj[pos].size(); i++){
		for(int j = 0; j < mid; j++){
			if(parent[adj[pos][i]][j] == -1 or dfs(parent[adj[pos][i]][j])){
				parent[adj[pos][i]][j] = pos;
				return true;
			}
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n, k;
	std::cin >> n >> k;
	
	int vote1 = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			votable[j] = true;
		}

		int l;
		std::cin >> l;

		for(int j = 0; j < l; j++){
			int ind;
			std::cin >> ind;

			ind--;

			if(j != 0){
				votable[ind] = false;
			}
		}
		
		if(votable[0]){
			vote1++;
			i--;
			n--;
			continue;
		}

		for(int j = 0; j < k; j++){
			if(votable[j]){
				adj[i].push_back(j);
			}
		}
	}

	int l = 0, r = n;

	while(l <= r){
		mid = (l + r) / 2;

		for(int i = 0; i < k; i++){
			for(int j = 0; j < mid; j++){
				parent[i][j] = -1;
			}
		}
		
		for(int i = 0; i < n; i++){
			used[i] = false;
		}

		int notlinked = 0;

		for(int i = 0; i < n; i++){
			if(!dfs(i)){
				notlinked++;
			}
		}

		if(notlinked > mid + 1 - vote1){
			l = mid + 1;
		} else {
			res = std::min(res, std::max(0, mid + 1 - vote1));
			r = mid - 1;
		}
	}

	std::cout << res;
}