#include <bits/stdc++.h>

typedef long long ll;

static int val[100010];
static int val2[100010];
static int found[100010];
static int found2[100010];

int main(){
	std::ios::sync_with_stdio(false);
	int n, x;
	std::cin >> n >> x;

	int best_res = -1;

	for(int i = 0; i < n; i++){
		std::cin >> val2[i];
		val[val2[i]]++;
		found2[val2[i] & x]++;

		if(val[val2[i]] >= 2){
			best_res = 0;
		}
		if(found2[val2[i] & x] >= 2){
			if(best_res == -1){
				best_res = 2;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(val[val2[i] & x] and (val2[i] & x) != val2[i]){
			if(best_res != 0){
				best_res = 1;
			}
		}
	}

	std::cout << best_res;
}