#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 55;
const int maxy = 11;
int n, k;
std::vector<int> x_given_y[maxy];
std::map<std::vector<int>, int> m;
std::vector<std::pair<int, int>> v_array;
int x[maxn];
int y[maxn];

int dfs(std::vector<int>& v, int used){
	if(used == n){
		return 0;
	}
	int& res = m[v];
	if(res != 0){
		return res;
	}

	int increase = 0;
	int y_sum_left = 0;

	for(int i = 0; i < maxy; i++){
		if(!x_given_y[i].empty()){
			y_sum_left += ((int) x_given_y[i].size() - v[i]) * i;
		}
	}

	int most_x_found = 0;
	for(int i = 0; i < maxy; i++){
		if(v[i] < x_given_y[i].size() and most_x_found < x_given_y[i][v[i]]){
			v[i]++;

			int attempt = x_given_y[i][v[i] - 1] * y_sum_left;
			attempt += dfs(v, used + 1);

			res = std::max(res, attempt);

			v[i]--;
		}
		if(v[i] < x_given_y[i].size()){
			most_x_found = std::max(most_x_found, x_given_y[i][v[i]]);
		}
	}

	if(2 * used == n){
		res += k * y_sum_left;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	v_array.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> x[i] >> y[i];
		v_array[i].first = x[i], v_array[i].second = y[i];

		x_given_y[y[i]].push_back(x[i]);
	}

	for(int i = 0; i < maxy; i++){
		if(!x_given_y[i].empty()){
			std::sort(x_given_y[i].begin(), x_given_y[i].end(), std::greater<int>());
		}
	}
	std::sort(v_array.begin(), v_array.end(), std::greater<std::pair<int, int>>());

	for(int i = 0; i < n; i++){
		x[i] = v_array[i].first;
		y[i] = v_array[i].second;
	}

	std::vector<int> v(maxy, 0);

	std::cout << dfs(v, 0) << '\n';
}
