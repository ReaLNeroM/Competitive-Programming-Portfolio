#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int table[maxn][26];

int main(){
	std::ios::sync_with_stdio(false);

	int test_cases;
	std::cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++){
		int n, q;
		std::cin >> n >> q;

		std::string s;
		std::cin >> s;

		for(int i = 1; i <= n; i++){
			for(char c = 'A'; c <= 'Z'; c++){
				table[i][c - 'A'] = table[i - 1][c - 'A'];
				if(c == s[i - 1]){
					table[i][c - 'A']++;
				}
			}
		}

		int res = 0;
		
		for(int i = 0; i < q; i++){
			int l, r;
			std::cin >> l >> r;

			int odd = 0;

			for(int j = 0; j < 26; j++){
				odd += (table[r][j] - table[l - 1][j]) % 2;
			}

			if((r - l + 1) % 2 == 0 and odd == 0){
				res++;
			} else if((r - l + 1) % 2 == 1 and odd <= 1){
				res++;
			}
		}

		std::cout << "Case #" << test_case << ": " << res << '\n';
	}

}