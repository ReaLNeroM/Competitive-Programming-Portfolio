#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int n;
int a[maxn], b[maxn];
int par[maxn];
int dist[maxn];
std::map<int, int> m, rev;
std::vector<int> adj[maxn];

int good(int query){
	for(int i = 0; i < n; i++){
		adj[i].clear();
		par[i] = -1;
	}

	for(int i = 0; i < n; i++){
		if(query < a[i]){
			return false;
		} else if(a[i] <= query and query < b[i]){
			adj[a[i]].push_back(a[i]);
		} else {
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
	}

	for(int i = 1; i <= n; i++){
		if(par[i] == -1){
			std::queue<int> q;
			q.push(i);
			dist[i] = 0;

			int floop = -1, sloop = -1;

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : adj[fr]){
					if(par[next] == -1){
						par[next] = fr;
						dist[next] = dist[fr] + 1;
					} else if(next != par[fr]){
						floop = fr;
						sloop = next;
						break;
					}
				}
			}

			if(floop != -1 and sloop != -1){
				adj[floop].erase(std::find(adj[floop].begin(), adj[floop].end(), sloop));
				adj[sloop].erase(std::find(adj[sloop].begin(), adj[sloop].end(), floop));				
			}
		}
	}

	std::fill(par, par + n + 1, -1);
	std::fill(dist, dist + n + 1, 0);

	for(int i = 1; i <= n; i++){
		if(par[i] == -1){
			std::queue<int> q;
			q.push(i);
			dist[i] = 0;

			int floop = -1, sloop = -1;

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : adj[fr]){
					if(par[next] == -1){
						par[next] = fr;
						dist[next] = dist[fr] + 1;
					} else if(next != par[fr]){
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> a[i] >> b[i];
		m[a[i]] = 0, m[b[i]] = 0;
	}

	int ind = 1;
	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = ind;
		rev[ind] = ite->first;
	}

	for(int i = 0; i < n; i++){
		a[i] = m[a[i]];
		b[i] = m[b[i]];

		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	int l = 1, r = ind;
	int best = -1;

	while(l <= r){
		int mid = (l + r) / 2;

		if(good(mid)){
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	if(best != -1){
		best = rev[best];
	}
	std::cout << best << '\n';
}