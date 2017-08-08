#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;

struct dsu {
	dsu* par = this;
	int rank = 0;
	int highest_ind = -1;	
	
	dsu* head(){
		if(par != par->par){
			par = par->head();
		}
		
		return par;
	}
	
	void merge(dsu* second){
		dsu* fir = head();
		dsu* sec = second->head();
		int highest = std::min(fir->highest_ind, sec->highest_ind);
		fir->highest_ind = sec->highest_ind = highest;
		
		if(fir->rank > sec->rank){
			sec->par = fir;
		} else if(fir->rank < sec->rank){
			fir->par = sec;
		} else {
			sec->par = fir;
			fir->rank++;
		}
	}
};

struct path {
	int x, y, lca;
};

std::vector<int> adj[maxn];
std::vector<std::vector<int> > interest[maxn];
int col[maxn];
dsu d[maxn];
path p[maxn];

int node_ind[maxn];
int node_size[maxn];
int curr_ind = 0;
int seg[8 * maxn];

void dfs_lca(int pos, int par){
	col[pos] = 1;
	
	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs_lca(adj[pos][i], pos);
		}
	}
	
	for(int i = 0; i < interest[pos].size(); i++){
		int other_node = interest[pos][i][0];
		
		if(col[other_node] == 2){
			p[interest[pos][i][1]].lca = d[other_node].head()->highest_ind;
		}
	}
	
	col[pos] = 2;
	if(par != -1){
		d[pos].merge(&d[par]);
	}
}

void dfs_pre(int pos, int par){
	node_ind[pos] = curr_ind;
	curr_ind++;
	
	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs_pre(adj[pos][i], pos);
		}
	}
	
	node_size[pos] = curr_ind - node_ind[pos];
}

void build(int cl, int cr, int ind){
	if(cl == cr){
		seg[ind] = 1;
		return;
	}
	
	int mid = (cl + cr) / 2;
	
	build(cl     , mid, 2 * ind + 1);
	build(mid + 1, cr , 2 * ind + 2);
	
	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n, paths;
	std::cin >> n >> paths;
		
	for(int i = 0; i < n; i++){
		d[i].highest_ind = i;
	}
	
	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;
		
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	
	for(int i = 0; i < paths; i++){
		int f, s, num;
		std::cin >> f >> s >> num;	
		f--, s--, num--;
		
		p[num].x = f;
		p[num].y = s;
		
		if(f == s){
			p[num].lca = f;	
		} else {
			interest[f].push_back({s, num});
			interest[s].push_back({f, num});
		}
	}
	
	dfs_lca(0, -1);
	
	dfs_pre(0, -1);
	
	build(0, n - 1, 0);
	
	ll sum = 0;
	
	for(int i = 0; i < paths; i++){
		if(p[i].lca == p[i].x or p[i].lca == p[i].y){
			
		} else {
			
		}
	}
	
	std::cout << sum << std::endl;
}