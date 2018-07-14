#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
std::vector<int> divisors[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 1; i < maxn; i++){
		for(int j = i; j < maxn; j += i){
			divisors[j].push_back(i);
		}
	}

	for(int i = 0; i < n; i++){
		std::vector<int> v(3);
		std::cin >> v[0] >> v[1] >> v[2];
		std::sort(v.begin(), v.end());

		int res = divisors[v[0]].size() * divisors[v[1]].size() * divisors[v[2]].size();

		std::cout << res << '\n';
	}
}
