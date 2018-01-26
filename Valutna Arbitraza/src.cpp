#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 25;
const double target = std::log(1.01);
const double INF = 1e18;
double val[maxn][maxn][maxn];
std::vector<int> res;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			for(int k = 0; k < maxn; k++){
				val[i][j][k] = -INF;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[1][i][j];
			val[1][i][j] = std::log(val[1][i][j]);
		}
	}

	for(int step = 2; step <= n; step++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				val[step][i][j] = -INF;
				for(int k = 0; k < n; k++){
					val[step][i][j] = std::max(val[step][i][j], val[step - 1][i][k] + val[1][k][j]);
				}
			}
		}
	}


	for(int step = 2; step <= n; step++){
		for(int i = 0; i < n; i++){
			if(val[step][i][i] > target){
				res.resize(step + 1);

				int pos = i;
				double accumulated = 0.0;

				for(int curr_step = 1; curr_step <= step; curr_step++){
					res[curr_step - 1] = pos;
					
					for(int j = 0; j < n; j++){
						if(accumulated + val[1][pos][j] + val[step - curr_step][j][i] > target){
							accumulated += val[1][pos][j];
							pos = j;
							j = n;
							break;
						}
					}
				}
				res[step] = i;

				step = maxn, i = n;
			}
		}
	}

	if(res.empty()){
		std::cout << "ne postoi profitabilna sekvenca\n";
	}

	for(int i = 0; i < res.size(); i++){
		std::cout << res[i] + 1;
		if(i != res.size() - 1){
			std::cout << '-';
		}
	}
}
