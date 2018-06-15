#include <bits/stdc++.h>

typedef long long ll;

const int MIN_Y = 10000;
const int maxn = 1e5 + 1e2;

struct dsu {
	dsu* parent = this;
	int rank = 0;
	int index;

	dsu* head(){
		if(parent != parent->parent){
			return parent->head();
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

		sec->parent = fir;
	}
};

int x1[maxn], x2[maxn], y1[maxn], y2[maxn];
std::vector<int> in[maxn], out[maxn];
std::map<int, std::pair<int, int>> inter;
dsu node[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		y1[i] += MIN_Y;
		y2[i] += MIN_Y;
	
		in[y1[i]].push_back(i);
		out[y2[i]].push_back(i);

		node[i].index = i;
	}

	for(int i = 0; i < maxn; i++){
		if(!in[i].empty()){
			for(int index : in[i]){
				auto ite = inter.upper_bound(x1[i]);
				int lowest = x1[i];
				int highest = x2[i];

				while(ite != inter.end() and x2[i] > ite->second.first){
					int old_index = ite->second.second;
					node[old_index].merge(&node[index]);

					lowest = std::min(lowest, ite->second.first);
					highest = std::max(highest, ite->first);
					auto sec = ite;
					ite++;
					inter.erase(sec);
				}

				inter[highest] = {lowest, node[i].head()->ind};

			}
		}
		if(!out[i].empty()){
			for(int index : out[i]){
				
			}
		}
	}

	// broj na oblasti so segment??
	// BROJ NA OBLASTI
	// PLOSTINA
	// PLOSTINA NA NAJGOLEMA
}