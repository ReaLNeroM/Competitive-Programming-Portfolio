#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;

int val[maxn];
std::multiset<int> intervals;
std::map<int, int> m;

struct dsu {
	dsu* parent = this;
	int rank = 0;
	int size = 1;
	bool open = false;

	dsu* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}

	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		if(fir->rank < sec->rank){
			std::swap(fir, sec);
		}

		if(fir->rank == sec->rank){
			fir->rank++;
		}

		fir->size = sec->size = fir->size + sec->size;

		sec->parent = fir;
	}
};

dsu component[maxn];

void unite(int new_node, int big_component){
	bool insert = false;

	if(!component[new_node].open){
		component[new_node].open = true;
		insert = true;
	}
	if(component[big_component].head()->open){
		auto ite = intervals.find(component[big_component].head()->size);
		if(ite != intervals.end()){
			intervals.erase(ite);
		}

		if(!insert){
			ite = intervals.find(component[new_node].head()->size);
			if(ite != intervals.end()){
				intervals.erase(ite);
			}
		}

		component[big_component].merge(&component[new_node]);

		insert = true;
	}

	if(insert){
		intervals.insert(component[new_node].head()->size);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		m[val[i]] = i;
	}

	std::vector<int> res = {0, -val[0]};

	for(auto ite = m.begin(); ite != m.end(); ite++){
		int pos = ite->second;
		int prev = pos - 1;
		int next = pos + 1;

		if(0 <= prev and prev < n){
			unite(pos, prev);
		}
		if(0 <= next and next < n){
			unite(pos, next);
		}

		if(!intervals.empty() and *intervals.begin() == *intervals.rbegin()){
			res = std::max(res, {(int) intervals.size(), -ite->first});
		}
	}

	std::cout << -res[1] + 1 << '\n';
}
