#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct unionset {
	unionset *parent = this;
	bool printed = false;
	int size = 1;

	unionset* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}
	void merge(unionset* next){
		next = next->head();
		head()->size += next->size;
		next->parent = head();
	}
};
int main() {
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	vector<int> adj[v];
	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;

		adj[f - 1].push_back(s - 1);
	}

	bool touch[v][v];
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			touch[i][j] = false;
		}
	}
	unionset u[v];
	for(int i = 0; i < v; i++){
		queue<int> q;
		touch[i][i] = true;
		q.push(i);

		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int j = 0; j < adj[fr].size(); j++){
				if(!touch[i][adj[fr][j]]){
					touch[i][adj[fr][j]] = true;
					q.push(adj[fr][j]);
				}
			}
		}

		for(int j = 0; j < v; j++){
			if(i != j and touch[i][j] == true and touch[j][i] == true and u[i].head() != u[j].head()){
				u[i].merge(&u[j]);
			}
		}
	}

	int minn = v, maxx = 0;
	for(int i = 0; i < v; i++){
		if(!u[i].head()->printed){
			u[i].head()->printed = true;
			maxx = max(maxx, u[i].head()->size);
			minn = min(minn, u[i].head()->size);
		}
	}

	cout << maxx << endl << minn;
	return 0;
}
