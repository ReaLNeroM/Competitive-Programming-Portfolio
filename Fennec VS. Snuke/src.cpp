#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e5 + 1e2;
int dist[maxn];
int par[maxn];
int imp[maxn];
std::vector<int> adj[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n;
	std::cin >> n;
	
	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;
		
		adj[f].push_back(s);	
		adj[s].push_back(f);	
	}
	
	std::fill(dist, dist + maxn, -1);
	
	std::queue<int> q;
	q.push(0);
	dist[0] = 0;
	
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		
		for(int i = 0; i < adj[fr].size(); i++){
			int next = adj[fr][i];
			
			if(dist[next] == -1){
				dist[next] = dist[fr] + 1;
				par[next] = fr;
				q.push(next);
			}
		}
	}
	
	int pos = n - 1;
	
	while(pos != 0){
		imp[pos] = true;
		pos = par[pos];
	}
	
	std::vector<int> white;
	
	for(int i = 0; i < n; i++){
		if(imp[i] and dist[i] <= dist[n - 1] / 2){
			white.push_back(i);
		}
	}
	
	int sum = 0;
	
	while(!white.empty()){
		int fr = white[white.size() - 1];
		white.pop_back();
		sum++;
		
		for(int i = 0; i < adj[fr].size(); i++){
			int next = adj[fr][i];
			
			if(!imp[next]){
				imp[next] = true;
				white.push_back(next);
			}
		}
	}
	
	if(sum > n - sum){
		std::cout << "Fennec";
	} else {
		std::cout << "Snuke";
	}
}