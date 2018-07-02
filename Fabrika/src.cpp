#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::map<int, std::multiset<int> > s;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < m; i++){
		int l, r;
		std::cin >> l >> r;
		s[l].insert(r);
	}

	int res = 0;
	while(!s.empty()){
		int pos = 0;
		res++;

		while(true){
			if(s.lower_bound(pos) == s.end()){
				break;
			}

			auto& curr_set = s.lower_bound(pos)->second;
			int end = *(curr_set.begin());
			curr_set.erase(curr_set.begin());
			if(curr_set.empty()){
				s.erase(s.lower_bound(pos));
			}
			pos = end + 1;
		}
	}

	std::cout << res << '\n';
}
