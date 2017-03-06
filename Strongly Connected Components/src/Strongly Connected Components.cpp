#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100;
vector<int> adj[maxn];
int dfs_low[maxn];
int dfs_num[maxn];
int state[maxn];
vector<int> v;
int curr = 0;

void dfs(int pos){
	state[pos] = 1;
	
	v.push_back(pos);
	dfs_num[pos] = dfs_low[pos] = curr;
	curr++;

	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(state[nnext] == 0){
			dfs(nnext);
		}

		if(state[nnext] == 1){
			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		}
	}

	if(dfs_num[pos] == dfs_low[pos]){
		while(true){
			int front = *v.rbegin();
			v.pop_back();

			cout << front << ' ';

			if(front == pos){
				break;
			}
		}
		cout << endl;
	}
}

int main(){
	int v, e;
	cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;

		adj[f].push_back(s);
	}

	for(int i = 0; i < v; i++){
		if(state[i] == 0){
			dfs(i);
		}
	}
}