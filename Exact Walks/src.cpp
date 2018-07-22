#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
int v, e;
int color[maxn];
int used[maxn];
std::vector<int> adj[maxn];
std::vector<int> sec[maxn];

int check(){
	for(int i = 0; i < v; i++){
		bool found = true;
		for(int j : adj[i]){
			for(int k : adj[j]){
				if(k == i){
					found = false;
				}
			}
		}

		if(found)
			return i;
	}

	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	if(check() == -1){
		std::cout << "NO\n";
		return 0;
	}

	std::cout << "YES\n";
	for(int i = 0; i < v; i++){
		std::cout << color[i] + 1 << ' ';
	}
	std::cout << '\n';
}
