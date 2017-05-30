#include <bits/stdc++.h>

const int maxn = 1e4;
const int maxlogn = 20;
int ind[maxn][maxlogn];
int other[maxn][maxlogn];
int par[maxn][maxlogn];

bool smaller(int a, int b){
	std::cout << "Q " << a + 1 << ' ' << b + 1 << std::endl;
	
	int res;
	std::cin >> res;
		
	return res == (a + 1);
}

int main() {
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		ind[i][0] = i;
		other[i][0] = -1;
		par[i][0] = -1;
	}

	int biggest_skip = 0;
	
	for(int skip = 1, logskip = 0; skip < n; skip *= 2, logskip++){
		for(int i = 0; i < n; i += skip * 2){
			if(i + skip < n){
				if(smaller(ind[i][logskip], ind[i + skip][logskip])){
					ind[i][logskip + 1] = ind[i][logskip];
					other[i][logskip + 1] = ind[i + skip][logskip];
					par[i][logskip + 1] = i;
				} else {
					ind[i][logskip + 1] = ind[i + skip][logskip];
					other[i][logskip + 1] = ind[i][logskip];
					par[i][logskip + 1] = i + skip;
				}
			} else {
				ind[i][logskip + 1] = ind[i][logskip];
				other[i][logskip + 1] = -1;
				par[i][logskip + 1] = i;
			}
		}
		
		biggest_skip = logskip + 1;
	}

	std::vector<int> v;
	int pos = 0;

	for(int i = biggest_skip; i > 0; i--){
		if(other[pos][i] != -1){
			v.push_back(other[pos][i]);
		}
		pos = par[pos][i];
	}

	int res = 0;
	for(int i = 1; i < v.size(); i++){
		if(smaller(v[i], v[res])){
			res = i;
		}
	}

	std::cout << "A " << v[res] + 1;
}