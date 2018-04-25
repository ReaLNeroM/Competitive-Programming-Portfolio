#include <bits/stdc++.h>

const int maxn = 50005 + 1e2;
const int maxk = 105 + 1e2;

int val[maxn][2][2];
int tagged[maxn][2];
int n, l, k;

int inf = 2000000000;
int best_index[2];
int best_value[2];

bool find_count(double time){
	best_value[0] = 0, best_value[1] = l;
	best_index[0] = -1, best_index[1] = -1;

	for(int i = 0; i < n; i++){
		if(!tagged[i][0] and best_value[0] < val[i][0][1] * (time - val[i][0][0])){
			best_value[0] = val[i][0][1] * (time - val[i][0][0]);
			best_index[0] = i;
		}
		if(!tagged[i][1] and best_value[1] > l + -val[i][1][1] * (time - val[i][1][0])){
			best_value[1] = l + -val[i][1][1] * (time - val[i][1][0]);
			best_index[1] = i;
		}

		if(best_value[1] <= best_value[0]){
			return true;
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> l >> k;

	for(int j = 0; j < 2; j++){
		for(int i = 0; i < n; i++){
			std::cin >> val[i][j][0] >> val[i][j][1];
		}
	}

	double l = 0.0;
	for(int i = 0; i < k; i++){
		double r = inf;
		double best = inf;

		for(int j = 0; j < 40; j++){
			double mid = (l + r) / 2.0;

			if(find_count(mid)){
				r = mid;
				best = mid;
			} else {
				l = mid;
			}
		}

		find_count(best);

		std::cout << best_index[0] + 1 << ' ' << best_index[1] + 1 << '\n';
		tagged[best_index[0]][0] = true;
		tagged[best_index[1]][1] = true;
	}
}
