#include <bits/stdc++.h>

typedef long long ll;

const double eps = 0.00000000001;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--){
		int n, k, x, d;
		std::cin >> n >> k >> x >> d;

		double now = 0;
		double special = -d;

		for(int i = 0; i < n; i++){
			int get;
			std::cin >> get;

			special += get;
			now += (double) get;
			now -= std::max((double) k, (double) get * (double) x / 100.0);
		}

		if(now >= special - eps){
			std::cout << "fee\n";
		} else {
			std::cout << "upfront\n";
		}
	}
}