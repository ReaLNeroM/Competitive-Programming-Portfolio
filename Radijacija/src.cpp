#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1582;
std::vector<int> incr[maxn];
std::vector<int> step[maxn];
std::vector<int> v[2500005];
bool swapped = false;

int main(){
	std::ios::sync_with_stdio(false);

	ll y, x;
	std::cin >> y >> x;

	if(x > maxn){
		swapped = true;
		std::swap(y, x);
	}

	for(int i = 0; i <= y; i++){
		incr[i].resize(x + 5, 0);
		step[i].resize(x + 5, 0);
		v[i].resize(x + 5, 0);
	}

	int elektrani;
	std::cin >> elektrani;

	for(int i = 0; i < elektrani; i++){
		int y1, x1, start, step;
		std::cin >> y1 >> x1 >> start >> step;
		if(swapped){
			std::swap(y1, x1);
		}

		int jumps = (start - 1) / step;
	}

	for(int startx = 1; startx <= x; startx++){
		int currsum = 0;
		int currstep = 0;

		for(int i = y, j = startx; i >= 1 and j >= 1; i--, j--){
			currsum += currstep;
			currsum += incr[i][j];
			currite += step[i][j];
			v[i][j] = currsum;
		}
	}
	
	for(int starty = 1; starty <= y - 1; starty++){
		int currsum = 0;
		int currstep = 0;

		for(int i = starty, j = x; i >= 1 and j >= 1; i--, j--){
			currsum += currstep;
			currsum += incr[i][j];
			currite += step[i][j];
			v[i][j] = currsum;
		}
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			v[i][j] = v[i][j] + v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
		}
	}

	int queries;
	std::cin >> queries;

	for(int i = 0; i < queries; i++){
		int y1, x1, y2, x2;
		std::cin >> y1 >> x1 >> y2 >> x2;
		if(swapped){
			std::swap(y1, x1);
			std::swap(y2, x2);
		}

		ll res = v[y2][x2] - v[y2][x1 - 1] - v[y1 - 1][x2] + v[y1 - 1][x1 - 1];
		ll del = (y2 - y1 + 1) * (x2 - x1 + 1);

		res += del / 2;
		res /= del;

		std::cout << res << '\n';
	}
}