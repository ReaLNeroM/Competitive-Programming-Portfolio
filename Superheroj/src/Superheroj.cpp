#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<int> adj[n];
	for(int i = 0; i < m; i++){
		int first, second;
		cin >> first >> second;

		adj[first - 1].push_back(second - 1);
		adj[second - 1].push_back(first - 1);
	}

	int s, e;
	cin >> s >> e;

	int moves[n];
	for(int i = 0; i < n; i++){
		moves[i] = -1;
	}
	moves[s - 1] = 0;

	queue<int> q;
	q.push(s - 1);

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int i = 0; i < adj[fr].size(); i++){
			if(moves[adj[fr][i]] == -1){
				moves[adj[fr][i]] = moves[fr] + 1;
				q.push(adj[fr][i]);
			}
		}
	}

	if(moves[e - 1] == -1){
		cout << 0;
	} else {
		cout << moves[e - 1];
	}
	return 0;
}
