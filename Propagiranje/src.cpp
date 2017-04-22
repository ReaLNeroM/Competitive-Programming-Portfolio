#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 12;
const int max_repre = 177148;
double dp[max_repre][maxn];
double dist[maxn][maxn];
bool used[max_repre][maxn];
int x[maxn], y[maxn];
int vlijanie[maxn];
int n;
 
double euclid(double a, double b){
	return std::sqrt(a * a + b * b);
}
 
double dfs(int base, int pos){
	if(!used[base][pos]){
		used[base][pos] = true;

 		double sum = 0.0;
		std::vector<int> vv, representation;

		for(int i = 0; i < n; i++){
			representation.push_back((base / vlijanie[i]) % 3);
			if(representation[i] == 1){
				vv.push_back(i);
			} else if(representation[i] == 2){
				sum += dist[pos][i];
			}
		}
 	
		if(vv.size() == 0){
			dp[base][pos] = 0.0;
		} else {
			dp[base][pos] = 1e18;
 
			for(int j = 1; j < (1 << vv.size()); j++){
				int accul = 0;
				int other = 0;
				for(int k = 0; k < n; k++){
					if(representation[k] == 2){
						other += 2 * vlijanie[k];
					}
				}
				for(int k = 0; k < vv.size(); k++){
					if(((1 << k) & j) != 0){
						accul += vlijanie[vv[k]];
					} else {
						other += vlijanie[vv[k]];
					}
				}
 
				for(int k = 0; k < vv.size(); k++){
					if(((1 << k) & j) != 0){
						other += 2 * vlijanie[vv[k]];
						accul -= vlijanie[vv[k]];
						dp[base][pos] = std::min(dp[base][pos], 
													std::max(sum + dist[pos][vv[k]] + dfs(accul, vv[k]), 
																dfs(other, pos)));
						accul += vlijanie[vv[k]];
						other -= 2 * vlijanie[vv[k]];
					}
				}
			}
		}
	}
 
	return dp[base][pos];
}
 
int main(){
	std::ios::sync_with_stdio(false);
 
	std::cin >> n;
 
	for(int i = 0; i < n; i++){
		std::cin >> x[i] >> y[i];
	}
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = euclid(y[j] - y[i], x[j] - x[i]);
		}
	}
 
	for(int i = 0; i < max_repre; i++){
		for(int j = 0; j < maxn; j++){
			used[i][j] = false;
			dp[i][j] = -1;
		}
	}
 
	vlijanie[0] = 1;
	for(int i = 1; i <= n; i++){
		vlijanie[i] = vlijanie[i - 1] * 3;
	}

	int at_start = 0;
	for(int i = 1; i < n; i++){
		at_start += vlijanie[i];
	}

	std::cout.precision(9);
	std::cout << std::fixed << dfs(at_start, 0) << std::endl;
}