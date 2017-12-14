#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int res[maxn];
std::vector<int> targ[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	int m, n;
	std::cin >> m >> n;
	
	for(int i = 0; i < n; i++){
		int l, r;
		std::cin >> l >> r;
		
		l--, r--;
		
		targ[l].push_back(i);
		targ[r + 1].push_back(-(i + 1));
	}
	
	int full = 0;	
	std::set<int> curr_painters;
	for(int i = 0; i < m; i++){
		for(int j : targ[i]){
			if(j >= 0){
				curr_painters.insert(j);
			} else {
				j = -(j + 1);
				curr_painters.erase(curr_painters.find(j));
			}
		}

		if(curr_painters.size()){
			full++;
		}
		if(curr_painters.size() == 1){
			res[*curr_painters.begin()]++;
		}
	}
	
	for(int i = 0; i < n; i++){
		std::cout << m - (full - res[i]) << '\n';
	}
}