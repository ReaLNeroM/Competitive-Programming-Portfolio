#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
std::vector<int> choice[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}
	std::sort(val, val + n, std::greater<int>());

	for(int i = 0; i < n; i++){
		choice[i].resize(2);
		std::cin >> choice[i][0] >> choice[i][1];
	}

	std::multiset<int> s;
	int currpos = 0;
	int res = 0;

	std::sort(choice, choice + n, std::greater<std::vector<int>>());

	for(int i = 0; i < n; i++){
		while(currpos < n and choice[currpos][0] >= val[i]){
			s.insert(choice[currpos][1]);
			currpos++;
		}

		if(!s.empty()){
			res += *--s.end();
			s.erase(--s.end());
		}
	}

	std::cout << res << '\n';
}
