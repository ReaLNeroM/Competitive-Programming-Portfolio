#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 4e3 + 1e2;
const int maxthreshold = 150;
int val[maxn];
int found[maxn];
int gain[maxn][maxthreshold];
int lookup[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, q;
	std::cin >> n >> m >> q;

	for(int i = 0; i < n; i++){
		std::cin >> val[n - i - 1];
	}

	for(int i = 0; i < m; i++){
		std::string s;
		std::cin >> s;

		int x = 0;
		for(int j = 0; j < n; j++){
			x *= 2;
			if(s[j] == '1'){
				x++;
			}
		}
		found[x]++;
	}

	for(int i = 0; i < n; i++){
		lookup[(1 << i)] = i;
	}

	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < (1 << n); j++){
			int sum = 0;
			int i_copy = ((1 << n) - 1) ^ (i ^ j);
			while(i_copy){
				sum += val[lookup[i_copy & -i_copy]];
				i_copy -= i_copy & -i_copy;
			}

			if(sum < maxthreshold){
				gain[i][sum] += found[j];
			}
		}
	}

	for(int i = 0; i < q; i++){
		std::string s;
		int threshold;

		std::cin >> s >> threshold;
		int x = 0;
		for(int j = 0; j < n; j++){
			x *= 2;
			if(s[j] == '1'){
				x++;
			}
		}

		ll res = 0;

		for(int k = threshold; k >= 0; k--){
			res += gain[x][k];
		}

		std::cout << res << '\n';
	}
}