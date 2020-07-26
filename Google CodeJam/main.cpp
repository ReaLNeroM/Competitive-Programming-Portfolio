#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cout << "Case #" << testcase << ": ";

		int n, q;
		std::cin >> n >> q;

		for(int i = 0; i < n - 1; i++){
			std::cin >> val[i];
		}

		for(int i = 0; i < q; i++){
			int s, k;
			std::cin >> s >> k;

			s--;
			int a = s - 1, b = s;
			for(int j = 1; j < k; j++){
				if(a >= 0 and b < n){
					if(val[a] > val[b]){
						b++;
						s = b;
					} else {
						// val[a] != val[b] for all a, b.s
						s = a;
						a--;
					}
				} else if(a >= 0){
					s = a;
					a--;
				} else {
					b++;
					s = b;
				}
			}

			std::cout << s + 1 << ' ';
		}

		std::cout << '\n';
	}
}