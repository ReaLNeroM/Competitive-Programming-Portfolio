#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int in[maxn]; //indegree
int out[maxn];
bool tag[maxn]; //visited
bool tag2[maxn];//part of an odd cycle AND not contributed to a free node
std::map<std::string, int> m;
std::vector<int> innodes[maxn];
int dp[maxn][2];
int res = 0;

int id(std::string &x){
	int &return_value = m[x];

	if(return_value == 0){
		return_value = (int) m.size();
	}

	return return_value - 1;
}

int dfs(int pos, int odd){
	if(dp[pos][odd] == -1){
		int free = 1;

		int initial = 0;
		for(int next : innodes[pos]){
			initial += dfs(next, 0);
		}

		int& res = dp[pos][odd];

		if(odd == 1){
			res = free + initial;
		} else {
			res = free + initial;
			for(int next : innodes[pos]){
				res = std::min(res, initial - dfs(next, 0) + dfs(next, 1));
			}
		}
	}

	return dp[pos][odd];
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::string s_a, s_b;
		std::cin >> s_a >> s_b;

		int a = id(s_a), b = id(s_b);

		out[a] = b;
		if(a != b){
			in[b]++;
			innodes[b].push_back(a);
		}
	}

	if(n % 2 == 1){
		std::cout << -1 << '\n';
		return 0;
	}

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		if(out[i] == i){
			//start from here

			res += dfs(i, 0);
		}
	}
	std::cout << res << '\n';
}
