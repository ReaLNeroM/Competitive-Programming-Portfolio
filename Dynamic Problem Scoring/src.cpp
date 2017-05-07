#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 125;
const ll max_robots = 100000;
ll val[maxn][5];
int right[5];
int orig_right[5];

int calc_score(int pos, int contestants){
	int score = 0;

	for(int i = 0; i < 5; i++){
		if(val[pos][i] != -1){
			for(int j = 1, sub_score = 500; j <= 32; j *= 2, sub_score += 500){
				if(j == 32 or (contestants < right[i] * (j * 2) and right[i] * j <= contestants)){
					score += sub_score;
					score -= (sub_score / 250) * val[pos][i];
					break;
				}
			}
		}
	}

	return score;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			std::cin >> val[i][j];
			if(val[i][j] != -1){
				orig_right[j]++;
			}
		}
	}

	for(int i = 0; i < max_robots; i++){
		for(int j = 0; j < 5; j++){
			right[j] = orig_right[j];
		}

		for(int j = 0; j < 5; j++){
			if(val[0][j] != -1 and val[1][j] != -1){
				if(val[0][j] <= val[1][j]){
					//make all robots here unsuccessful
				} else if(val[0][j] > val[1][j]){
					right[j] += i;
					//make all robots here right
				}
			}
		}

		int get = calc_score(0, n + i) - calc_score(1, n + i);
		if(get > 0){
			std::cout << i << std::endl;
			return 0;
		}
	}

	std::cout << -1 << std::endl;
}