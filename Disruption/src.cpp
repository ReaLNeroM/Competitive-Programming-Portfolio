#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5e4 + 1e2;
int n, k;
int roadlength[maxn];
int id[maxn];
int par[maxn];
std::vector<std::vector<int>> adj[maxn];

struct cmp_struct {
	bool operator()(const int& a, const int& b){
		return roadlength[a] < roadlength[b];
	}
};

std::multiset<int, cmp_struct> aux[maxn];
int res[maxn];

void dfs(int pos){
	for(std::vector<int> next : adj[pos]){
		if(next[0] != par[pos]){
			id[next[0]] = next[1];
			par[next[0]] = pos;
			dfs(next[0]);
		}
	}
}

std::multiset<int, cmp_struct>* dfs2(int pos){
	std::multiset<int, cmp_struct>* head = &aux[pos];

	for(std::vector<int> next : adj[pos]){
		if(next[0] != par[pos]){
			std::multiset<int, cmp_struct>* child_vector = dfs2(next[0]);

			if(child_vector->size() > head->size()){
				std::swap(head, child_vector);
			}

			auto site = child_vector->begin();

			while(site != child_vector->end()){
				auto fite = head->find(*site);

				if(fite != head->end()){
					head->erase(fite);
				} else {
					head->insert(*site);
				}

				site++;
			}
		}
	}

	if(!head->empty()){
		res[id[pos]] = roadlength[*(head->begin())];
	}

	return head;
}

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("disrupt.in", "r", stdin);
		freopen("disrupt.out", "w", stdout);
	#endif

	std::cin >> n >> k;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back({s, i});
		adj[s].push_back({f, i});
	}

	std::fill(res, res + n, -1);

	id[0] = n;
	par[0] = -1;
	dfs(0);

	for(int i = 0; i < k; i++){
		int f, s;
		std::cin >> f >> s >> roadlength[i];
		f--, s--;

		aux[f].insert(i);
		aux[s].insert(i);
	}

	dfs2(0);

	for(int i = 0; i < n - 1; i++){
		std::cout << res[i] << '\n';
	}
}
