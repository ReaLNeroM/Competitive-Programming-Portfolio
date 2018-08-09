#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::vector<int> val[maxn];

int sum(std::vector<int> v){
	int sumv = 0;
	for(int i = 0; i < 4; i++){
		sumv += v[i];
	}
	return sumv;
}

bool cmp(std::vector<int> a, std::vector<int> b){
	return sum(a) > sum(b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		val[i].resize(5);
		std::cin >> val[i][0] >> val[i][1] >> val[i][2] >> val[i][3];
		val[i][4] = i;
	}

	std::stable_sort(val, val + n, cmp);

	for(int i = 0; i < n; i++){
		if(val[i][4] == 0){
			std::cout << i + 1 << '\n';
			return 0;
		}
	}
}