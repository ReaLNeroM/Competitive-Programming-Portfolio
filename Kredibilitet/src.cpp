#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 55;
int n, k;
std::vector<std::pair<int, int>> v;
int x[maxn];
int y[maxn];

int score(){
	int currx = 0;
	int res = 0;

	for(int i = 0; i < n; i++){
		if(i == n / 2){
			currx += k;
		}

		currx += x[i];
		res += currx * y[i];
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	v.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> x[i] >> y[i];
		v[i].first = x[i], v[i].second = y[i];
	}

	int res = 0;
	std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
	for(int i = 0; i < n; i++){
		x[i] = v[i].first;
		y[i] = v[i].second;
		std::cout << x[i] << ' ' << y[i] << '\n';
	}

	bool good = true;
	do {
		good = false;

		int curr_res = score();

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				std::swap(x[i], x[j]), std::swap(y[i], y[j]);
				if(score() > curr_res){
					curr_res = score();
					good = true;
				} else {
					std::swap(x[i], x[j]), std::swap(y[i], y[j]);
				}
			}
		}
	} while(good);

	res = std::max(res, score());

	std::cout << res << '\n';
}