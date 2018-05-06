#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e3 + 1e2;
const int maxalphabet = 26;

std::string s[maxn];
int allowed[maxn][maxalphabet];
int n, length;

bool equal(std::string& a, std::string& b, int check_length){
	for(int i = 0; i < check_length; i++){
		if(a[i] != b[i]){
			return false;
		}
	}

	return true;
}

bool dfs(int pos, int l, int r, std::string& res){
	if(pos == length){
		if(l <= r){
			return false;
		} else {
			return true;
		}
	}

	for(int i = 0; i < maxalphabet; i++){
		if(allowed[pos][i]){
			res += (char) ('A' + i);

			int new_r = l;
			while(new_r <= r and equal(s[new_r], res, pos + 1)){
				new_r++;
			}
			if(dfs(pos + 1, l, new_r - 1, res)){
				return true;
			}

			l = new_r;

			res.erase(res.begin() + res.size() - 1);
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		std::cin >> n >> length;

		memset(allowed, 0, sizeof(allowed));
		for(int i = 0; i < n; i++){
			std::cin >> s[i];

			for(int j = 0; j < length; j++){
				allowed[j][s[i][j] - 'A'] = true;
			}
		}

		std::sort(s, s + n);

		std::string res = "";
		dfs(0, 0, n - 1, res);

		if(res == ""){
			res = "-";
		}

		std::cout << "Case #" << test << ": " << res << '\n';
	}
}
