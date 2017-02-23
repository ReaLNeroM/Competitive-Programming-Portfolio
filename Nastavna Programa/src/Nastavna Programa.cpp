#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int vertices, edges;
	cin >> vertices >> edges;

	int votesneeded;
	cin >> votesneeded;

	vector<int> adj[vertices];
	for(int i = 0, first, second, votes; i < edges; i++){
		cin >> first >> second >> votes;

		if(votes <= votesneeded){
			adj[first].push_back(second);
			adj[second].push_back(first);
		}
	}

	int group[vertices];
	for(int i = 0; i < vertices; i++){
		group[i] = -1;
	}

	bool allgoodnthehood = true;
	for(int i = 0; i < vertices; i++){
		if(group[i] == -1){
			group[i] = 0;

			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int j = 0; j < adj[fr].size(); j++){
					if(group[fr] == group[adj[fr][j]]){
						allgoodnthehood = false;
					} else if(group[adj[fr][j]] == -1){
						group[adj[fr][j]] = !group[fr];
						q.push(adj[fr][j]);
					}
				}
			}
		}
	}

	if(allgoodnthehood){
		cout << "DA";
	} else {
		cout << "NE";
	}
	return 0;
}
