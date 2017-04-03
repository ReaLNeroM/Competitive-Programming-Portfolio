#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;
vector<int> adj[maxn];
int sub[maxn];

pair<int, int> dfs(int pos, int par){
	int time_taken = 0;
	sub[pos] = 1;

	vector<int> children;
	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(nnext != par){
			children.push_back(dfs(nnext, pos));
			sub[pos] += sub[nnext];
			children[children.size() - 1].first++;
		}
	}
	
	for(int i = 0; i < children.size(); i++){
		if(pos == 0){
			time_taken = max(time_taken, children[i]);
		} else {
			time_taken += children[i];
		}
	}

	return time_taken;
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	cout << dfs(0, -1).first - 1;
}
