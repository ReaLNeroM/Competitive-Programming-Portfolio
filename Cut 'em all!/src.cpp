#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int size[maxn];
std::vector<int> adj[maxn];
int res = 0;

void dfs(int pos, int par){
	size[pos] = 1;

	for(int next : adj[pos]){
		if(next != par){
			dfs(next, pos);
			size[pos] += size[next];
		}
	}

	if(size[pos] % 2 == 0 and pos != 0){
		res++;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	if(n % 2 == 1){
		res = -1;
	} else {
		dfs(0, -1);
	}

	std::cout << res << '\n';
}