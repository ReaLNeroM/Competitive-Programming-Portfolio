#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int sum = 0;
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		if(val[i] > 0){
			sum += val[i];		
		}
	}

	int res = -1e9;
	if(sum % 2 == 1){
		res = sum;
	} else {
		for(int i = 0; i < n; i++){
			if(val[i] < 0 and (-val[i]) % 2 == 1){
				res = std::max(res, sum + val[i]);
			} else if(val[i] > 0 and val[i] % 2 == 1){
				res = std::max(res, sum - val[i]);
			}
		}
	}

	std::cout << res << std::endl;
}