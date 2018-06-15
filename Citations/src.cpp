#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int length[maxn];
std::vector<int> adj[maxn];

bool cmp(std::pair<int, int> first, std::pair<int, int> second){
	return first.first * second.second < first.second * second.first;
}

std::pair<int, int> dfs(int index){
	if(adj[index].empty()){
		return {1 + length[index], 1};
	}

	std::vector<std::pair<int, int>> v(adj[index].size());

	for(int i = 0; i < adj[index].size(); i++){
		v[i] = dfs(adj[index][i]);
	}

	std::sort(v.begin(), v.end(), cmp);

	int res = 0;
	int v_sum_first = 0;

	for(int i = 0; i < v.size(); i++){
		res += v_sum_first * v[i].second;
		v_sum_first += v[i].first;
	}

	res += v_sum_first;

	return {1 + res + length[index], v.size() + 1};
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> length[i];

		int requisites;
		std::cin >> requisites;
		adj[i].resize(requisites);

		for(int j = 0; j < requisites; j++){
			std::cin >> adj[i][j];
			adj[i][j]--;
		}
	}

	std::cout << dfs(0).first << std::endl;
}