#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 65;
int v;
int built;
int add;
int val[maxn];
int exists[maxn];
vector<pair<int, int>> adj[maxn];
int mat[maxn][maxn];
int res = 1e9;

bool check(int pos, int dist){
	for(int i = 0; i < pos; i++){
		if(mat[i][pos] <= dist){
			return true;
		}
	}

	return false;
}

bool good(int dist){
	bool cycle[v];

	for(int i = 0; i < v; i++){
		if(exists[i] == 2){
			exists[i] = 0;
		}
	}

	for(int i = 0; i < v; i++){
		bool used[v];
		for(int j = 0; j < v; j++){
			used[j] = false;
		}
		queue<int> q, qpar;
		used[i] = true;
		q.push(i);
		qpar.push(-1);

		while(!q.empty()){
			int fr = q.front();
			int frpar = qpar.front();
			q.pop(), qpar.pop();

			for(int j = 0; j < adj[i].size(); j++){
				int next = adj[i][j].first;

				if(next != frpar and next == i){
					cycle[i] = true;
					while(!q.empty()){
						q.pop();
					}
					break;
				}
			}
		}
	}
	//start from leaves
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> v;
	cin >> built;
	cin >> add;

	for(int i = 0; i < built; i++){
		int ind;
		cin >> ind;
		exists[ind - 1] = true;
	}

	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			mat[i][j] = 1e9;
		}
		mat[i][i] = 0;
	}

	int e;
	cin >> e;

	for(int i = 0; i < e; i++){
		int f, s, c;
		cin >> f >> s >> c;
		f--, s--;

		adj[f].push_back({s, c});
		adj[s].push_back({f, c});
		mat[f][s] = min(mat[f][s], c);
	}

	for(int k = 0; k < v; k++){
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	int l = 0, r = 1e9;
	while(l <= r){
		int mid = (l + r) / 2;

		if(good(mid)){
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << res;
}

