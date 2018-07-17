#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
std::vector<int> divs[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 1; i < maxn; i++){
		for(int j = i; j < maxn; j += i){
			divs[j].push_back(i);
		}
	}

	std::vector<int> v(3);
	
	for(int query_index = 1; query_index <= n; query_index++){
		std::cin >> v[0] >> v[1] >> v[2];
		std::sort(v.begin(), v.end());

		int res = 0;

		std::cout << res << '\n';
	}
}
