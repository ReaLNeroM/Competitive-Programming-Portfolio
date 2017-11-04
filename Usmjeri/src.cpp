#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6;
const int mod = 1e9 + 7;

struct dsu {
	dsu* parent = this;
	int rank = 0;
	bool used = false;

	dsu* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}
	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		if(fir->rank > sec->rank){
			sec->parent = fir;
		} else if(sec->rank > fir->rank){
			fir->parent = sec;
		} else {
			sec->parent = fir;
			fir->rank++;
		}
	}
}

std::vector<int> v[maxn];
dsu u[maxn];
bool locked[maxn];
int running[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, pairs;
	std::cin >> n >> pairs;

	bool ez = true;

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;

		f--, s--;
		v[f].push_back({s, i});
		v[s].push_back({f, i});
	}

	if(ez){
		std::fill(changeable, changeable + maxn, true);

		for(int i = 0; i < pairs; i++){
			int f, s;
			std::cin >> f >> s;

			if(f > s){
				std::swap(f, s);
			}
			f--, s--;

			running[f + 1]++;
			running[s]--;
		}

		int res = 1;
		int sum = 0;
		for(int i = 0; i < n - 1; i++){
			sum += running[i];
			if(sum == 0){
				res *= 2;
				res %= mod;
			}
		}

		std::cout << res << '\n';
	} else {
		for(int i = 0; i < pairs; i++){
			int f, s;
			std::cin >> f >> s;

			//compute
		}

		int res = 1;

		for(int i = 0; i < n - 1; i++){
			if(!(u[i].head()->used)){
				res *= 2;
			}
		}
		
		std::cout << res << '\n';
	}
}