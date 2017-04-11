#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e3 + 1e2;
static int val[1000000];
static int available[3 * maxn];
vector<int> adj[3 * maxn];
static bool used[3 * maxn];

int main(){
	ios::sync_with_stdio(false);

	int goal, n;
	cin >> goal >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
		available[maxn + val[i] - goal] = true;
	}

	for(int i = 0; i < 3 * maxn; i++){
		for(int j = 0; j < 3 * maxn; j++){
			if(available[j] and (i - maxn) + (j - maxn) + maxn >= 0 and (i - maxn) + (j - maxn) + maxn < 3 * maxn){
				adj[i].push_back((i - maxn) + (j - maxn) + maxn);
			}
		}
	}

	queue<int> q, qdist;
	q.push(maxn), qdist.push(0);
	used[maxn] = true;

	bool res_found = false;
	int res = 1e9;

	while(!q.empty() and !res_found){
		int fr = q.front(), frdist = qdist.front();
		q.pop(), qdist.pop();

		for(int i = 0; i < adj[fr].size(); i++){
			int nnext = adj[fr][i];

			if(!used[nnext]){
				used[nnext] = true;
				q.push(nnext), qdist.push(frdist + 1);
			} else if(nnext == maxn){
				res_found = true;
				res = frdist + 1;
				break;
			}
		}
	}

	if(res_found){
		cout << res;
	} else {
		cout << -1;
	}
}