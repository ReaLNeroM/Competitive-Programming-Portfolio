#include <bits/stdc++.h>

typedef long long ll;

int main(){
	int n;
	std::cin >> n;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		adj[f].push_back(f);
		adj[s].push_back(f);
	}
}