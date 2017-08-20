#include <bits/stdc++.h>

typedef long long ll;

const double eps = 0.00000000001;

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;

	std::vector<std::vector<int>> v(n, {0, 0});

	for(int i = 0; i < n; i++){
		std::cin >> v[i][1];
	}
	for(int i = 0; i < n; i++){
		std::cin >> v[i][0];
	}

	std::vector<std::vector<int>> fstack, bstack;

	for(int i = 0; i < n; i++){
		if(fstack.empty() or fstack[fstack.size() - 1][0] < v[i][0]){
			fstack.push_back(v[i]);
		}
	}

	for(int i = n - 1; i >= 0; i--){
		if(bstack.empty() or bstack[bstack.size() - 1][0] < v[i][0]){
			bstack.push_back(v[i]);
		}
	}

	for(int i = 0; i < q; i++){
		int t;
		std::cin >> t;

		int value;
		std::cin >> value;

		if(t == 1){
			int l = 0, r = fstack.size() - 1;
			int best = -1;

			while(l <= r){
				int mid = (l + r) / 2;

				if(fstack[mid][0] >= value){
					best = fstack[mid][1];
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			std::cout << best << '\n';
		} else {
			int l = 0, r = bstack.size() - 1;
			int best = -1;

			while(l <= r){
				int mid = (l + r) / 2;

				if(value <= bstack[mid][1]){
					best = bstack[mid][0];
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}

			std::cout << best << '\n';
		}
	}
}