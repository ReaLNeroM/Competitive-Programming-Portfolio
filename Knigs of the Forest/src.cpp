#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
std::vector<std::vector<int>> ev[maxn + 2500];
std::map<int, int> m;

int main(){
	std::ios::sync_with_stdio(false);

	int k, n;
	std::cin >> k >> n;

	int y, p;
	std::cin >> y >> p;
	ev[y].push_back({p, 0});

	for(int i = 0; i < n + k - 2; i++){
		std::cin >> y >> p;
		ev[y].push_back({p, 1});
	}

	for(int i = 2011; i <= 2011 + n; i++){
		if(i == 2011 + n){
			std::cout << "unknown\n";
			break;
		}

		for(int j = 0; j < ev[i].size(); j++){
			m[ev[i][j][0]] = ev[i][j][1];
		}

		if((*m.rbegin()).second == 0){
			std::cout << i << std::endl;
			return 0;
		}

		m.erase(--m.end());
	}
}