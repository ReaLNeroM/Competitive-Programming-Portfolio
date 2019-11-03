#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 10;
const ll INF = 1000000000000000010;

int last[maxn][26];

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;

	int n = s.size();

	for(int i = 0; i < 26; i++){
		last[0][i] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++){
			last[i][j] = last[i - 1][j];
		}
		last[i][s[i - 1] - 'a'] = i;
	}

	memset(seen, 0, sizeof(seen));

	int res = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 26; j++){
			if(j == s[i - 1] - 'a'){
				continue;
			}

			int lastPos = i;
			int firstPos = last[i - 1][j];

			if(firstPos != 0 and last[lastPos - 1][s[i - 1] - 'a'] < firstPos){
				res++;
			}
		}
	}

	std::cout << res << '\n';
}