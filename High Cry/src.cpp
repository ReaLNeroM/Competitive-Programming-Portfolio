#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
const int maxbit = 30;
int val[maxn];
int app[maxbit];
ll res = 0;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	res = (long long) n * (n + 1) / 2;

	std::cout << res << '\n';
	for(int i = 0; i < n; i++){
		int earliest = 0;

		for(int j = 0, bit = 1; j < maxbit; j++, bit *= 2){
			if(!(bit & val[i])){
				earliest = std::max(earliest, app[j]);
			}
		}

		res -= earliest;

		for(int j = 0, bit = 1; j < maxbit; j++, bit *= 2){
			if(bit & val[i]){
				app[j] = i + 1;
			}

		}
	}

	std::cout << res << '\n';
}