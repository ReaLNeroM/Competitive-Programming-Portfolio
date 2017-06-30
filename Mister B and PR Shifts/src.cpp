#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int derivative1[maxn];
int derivative2[maxn];
ll curr = 0;
ll curr_change = 0;
ll res = 1e18;
ll res_pos = 0;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
		curr += std::abs(val[i] - i);
		if(i <= val[i]){
			derivative2[1]--;
			derivative2[val[i] - i + 1] += 2;
			derivative2[n - i]--;
			derivative1[n - i] += std::abs(val[i] - 0) - std::abs(val[i] - (n - 1));
			derivative2[n - i + 1]--;
		} else {
			derivative2[1]++;
			derivative2[n - i]--;
			derivative1[n - i] += std::abs(val[i] - 0) - std::abs(val[i] - (n - 1));
			derivative2[n - i + 1]--;
			derivative2[n - i + val[i] + 1] += 2;
		}
	}

	for(int i = 0; i < n; i++){
		curr_change += derivative2[i];
		curr += curr_change + derivative1[i];

		if(res > curr){
			res = curr;
			res_pos = i;
		}
	}

	std::cout << res << ' ' << res_pos << std::endl;
}
