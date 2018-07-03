#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;
	int n = s.size();

	ll res = 0;
	for(int i = 0; i < (1 << (n - 1)); i++){
		ll build = 0;

		for(int j = 0, bit = 1; j < n; j++, bit *= 2){
			build *= 10;
			build += (s[j] - '0');

			if((i & bit) or (j == n - 1)){
				res += build;
				build = 0;
			}
		}
	}

	std::cout << res << '\n';
}
