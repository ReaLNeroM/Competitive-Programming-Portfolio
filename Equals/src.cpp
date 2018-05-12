#include <bits/stdc++.h>

typedef long long ll;

struct dsu {
	dsu* parent = this;
	int rank = 0;

	dsu* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}
	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		if(fir == sec){
			return;
		}

		if(fir->rank < sec->rank){
			fir->parent = sec;
		} else if(fir->rank > sec->rank){
			sec->parent = fir;
		} else {
			sec->parent = fir;
			fir->rank++;
		}
	}
};

const int maxn = 1e5 + 1e2;
int p[maxn];
dsu node[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, edges;

	std::cin >> n >> edges;

	for(int i = 0; i < n; i++){
		std::cin >> p[i];
		p[i]--;
	}
	for(int i = 0; i < edges; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;

		node[a].merge(&node[b]);
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		if(node[i].head() == node[p[i]].head()){
			res++;
		}
	}

	std::cout << res << '\n';
}