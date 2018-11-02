#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
std::vector<int> adj[maxn];

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

	
}