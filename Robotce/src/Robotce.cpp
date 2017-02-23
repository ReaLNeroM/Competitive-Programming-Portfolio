#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

bool used[1001];
bool calc[1001];
vector<int> adj[1001];
int v, e;
int secondvisit = -1;

void dfs(int pos){
	if(calc[pos]){
		secondvisit = pos;
	}
	if(used[pos]){
		return;
	}
	used[pos] = true;

	calc[pos] = true;
	for(int i = 0; i < adj[pos].size(); i++){
		if(secondvisit == -1){
			dfs(adj[pos][i]);
		}
	}

	calc[pos] = false;
}
int main() {
	ios::sync_with_stdio(false);

	cin >> v >> e;

	for(int i = 0; i < v; i++){
		used[i] = false;
		calc[i] = false;
	}

	for(int i = 0; i < e; i++){
		int first, second;
		cin >> first >> second;

		adj[first].push_back(second);
	}

	dfs(0);

	if(secondvisit == -1){
		cout << "NE";
	} else {
		cout << secondvisit;
	}
	return 0;
}
