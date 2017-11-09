#include <bits/stdc++.h>

typedef long long ll;

const int maxx = 1e5 + 1e2;

struct dsu {
	dsu* parent = this;
	int ind;
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

		if(fir->rank > sec->rank){
			sec->parent = fir;
		} else if(fir->rank < sec->rank){
			fir->parent = sec;
		} else {
			sec->parent = fir;
			fir->rank++;
		}
	}
};

int prev[maxx];
int curr[maxx];
dsu u[2][maxx];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	int comps = 0;

	for(int j = 0; j < x; j++){
		u[0][j].ind = j;
		u[1][j].ind = j;
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			u[1][j].parent = &u[1][j];
			u[1][j].rank = 0;
		}

		for(int j = 0; j < x / 4; j++){
			char c;
			std::cin >> c;

			int binary;
			if(c >= 'A'){
				binary = 10 + (int) (c - 'A');
			} else {
				binary = c - '0';
			}

			for(int ind = j * 4 + 3, bit = 1; ind >= j * 4; ind--, bit *= 2){
				if(bit & binary){
					curr[ind] = true;
				} else {
					curr[ind] = false;
				}
			}
		}

		for(int j = 0; j < x; j++){
			if(curr[j]){
				comps++;

				if(j != 0 and curr[j - 1] and u[1][j].head() != u[1][j - 1].head()){
					u[1][j].merge(&u[1][j - 1]);
					comps--;
				}

				if(i != 0 and prev[j] and u[1][j].head() != u[0][j].head()){
					u[1][j].merge(&u[0][j]);
					comps--;
				}
			}
		}

		for(int j = 0; j < x; j++){
			u[0][j].parent = &u[0][j];
			u[0][j].rank = 0;
			u[0][j] = u[1][j];
			u[0][j].parent = &(u[0][u[1][j].head()->ind]);
			prev[j] = curr[j];
		}
	}

	std::cout << comps << '\n';
}