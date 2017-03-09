#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
const int maxn = 1005;
int bff[maxn];
int place[maxn];
int used[maxn];
vector<int> adj[maxn];
int res = 0;

void dfs(int pos, int curr){
	bool good = true;
	for(int i = 0; i < curr; i++){
		if(place[(i + curr - 1) % curr] == bff[place[i]]){
		} else if(place[(i + 1) % curr] == bff[place[i]]){
		} else {
			good = false;
		}
	}
	if(good){
		res = max(res, curr);
	}

	if(bff[pos] == place[curr - 2]){
		for(int i = 0; i < adj[i].size(); i++){
			int nnext = adj[pos][i];
			if(!used[nnext]){
				used[nnext] = true;
				place[curr] = nnext;
				dfs(nnext, curr + 1);
				used[nnext] = false;
			}
		}
	} else if(!used[bff[pos]]){
		used[bff[pos]] = true;
		place[curr] = bff[pos];
		dfs(bff[pos], curr + 1);
		used[bff[pos]] = false;
	}
}

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			bff[j] = -1;
			place[j] = -1;
		}
		res = 0;	

		for(int i = 0; i < n; i++){
			cin >> bff[i];
			bff[i]--;
			adj[bff[i]].push_back(i);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				used[j] = false;
				place[j] = -1;
			}
			used[i] = true;
			place[0] = i;
			dfs(i, 1);
		}

		cout << "Case #" << i + 1 << ": ";
		cout << res;
		cout << endl;
	}
}