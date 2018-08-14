#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int INF = 2e9;
int n, x;
int val[maxn];
int usual[maxn];
int sufres[maxn];
int res = 0;

void solve(){
	std::fill(usual, usual + maxn, -INF);
	usual[0] = (*std::max_element(val, val + n)) + 1;
	memset(sufres, 0, sizeof(sufres));
	int size = 1;

	for(int i = n - 1; i >= 0; i--){
		int l = 0, r = size - 1;
		int best = -1;

		while(l <= r){
			int mid = (l + r) / 2;

			if(usual[mid] > val[i]){
				best = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		usual[best + 1] = std::max(usual[best + 1], val[i]);
		size = std::max(size, best + 2);
		sufres[i] = best + 1;
	}

	std::fill(usual, usual + maxn, INF);
	usual[0] = (*std::min_element(val, val + n)) - 1;
	size = 1;

	for(int i = 0; i < n; i++){
		int l = 0, r = size - 1;

		while(l <= r){
			int mid = (l + r) / 2;

			if(usual[mid] - x < val[i]){
				res = std::max(res, sufres[i] + mid);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		l = 0, r = size - 1;
		int best = -1;

		while(l <= r){
			int mid = (l + r) / 2;

			if(usual[mid] < val[i]){
				best = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		usual[best + 1] = std::min(usual[best + 1], val[i]);
		size = std::max(size, best + 2);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> n >> x;
	
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	solve();

	std::reverse(val, val + n);
	for(int i = 0; i < n; i++){
		val[i] *= -1;
	}

	x *= -1;
	
	solve();

	std::cout << res << '\n';
}
