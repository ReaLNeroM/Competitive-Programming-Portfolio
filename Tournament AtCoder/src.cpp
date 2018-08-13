#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::vector<int> v[maxn];
int a[maxn];
int appearances[maxn];

int dfs(int pos){
	if(v[pos].size() == 0){
		return 0;
	}

	std::vector<int> res(v[pos].size());
	for(int i = 0; i < v[pos].size(); i++){
		res[i] = dfs(v[pos][i]);
	}
	std::sort(res.begin(), res.end(), std::greater<int>());
	int return_value = 0;
	for(int i = 0; i < res.size(); i++){
		return_value = std::max(return_value, res[i] + i + 1);
	}

	return return_value;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	a[0] = -1;
	for(int i = 1; i < n; i++){
		std::cin >> a[i];
		a[i]--;

		v[a[i]].push_back(i);
	}

	std::cout << dfs(0) << '\n';
}
