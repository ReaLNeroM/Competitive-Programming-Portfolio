#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 25;
std::vector<int> p[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, p;
	std::cin >> n >> p;

	for(int i = 0; i < n; i++){
		p[i].resize(3);
		std::cin >> p[i][0] >> p[i][1] >> p[i][2];

		p[i][1] += p[i][0];
	}

	if(p == 1){
		std::sort(p, p + n);

		int curr_pos = 1;

		for(int i = 0; i < n; i++){

		}
	}
}
