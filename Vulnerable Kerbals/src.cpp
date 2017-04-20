#include <bits/stdc++.h>

typedef long long ll;

const int maxm = 2e5 + 1e2;

int gcd(int a, int b){
	while(b != 0){
		int temp = a % b;
		a = b;
		b = temp;
	}
	
	return a;
}

std::vector<int> factor[maxm];

int main(){
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	std::fill(allowed, allowed + m, true);

	for(int i = 0; i < n; i++){
		int val;
		std::cin >> val;

		allowed[val] = false;
	}

	if(allowed[0]){
		open[m] = true;
	}
	for(int i = 1; i < m; i++){
		if(allowed[i]){

		}
	}

	for(int i = 1; i < m; i++){
		for(int j = i; j < m; j += i){
			//do the edges
		}
	}

	int best = 0, bestid = -1;
	for(int i = 0; i < m; i++){
		if(dp[i] > best){
			best = dp[i];
			bestid = i;
		}
	}

	std::vector<int> best_path;
	best_path.push_back(bestid);
	while(bestid != 1){
		bestid = par[bestid];
		best_path.push_back(bestid);
	}

	int num = 1;

	std::vector<int> res;
	for(int i = best_path.size() - 1; i >= 0; i--){
		for(int j = 0; j < with_gcd[best_path[i]].size(); j++){
			int need = num 
		}
	}
}