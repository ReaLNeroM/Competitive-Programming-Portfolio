#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int lshoes, rshoes;
int ls[maxn], rs[maxn];

bool good(int maxpair){
	int lpos = 0;
	int rpos = 0;

	int paired = 0;

	while(lpos < lshoes and rpos < rshoes){
		if(std::abs(rs[rpos] - ls[lpos]) <= maxpair){
			lpos++, rpos++;
			paired++;
		} else if(ls[lpos] < rs[rpos]){
			lpos++;
		} else {
			rpos++;
		}
	}

	return (paired == std::min(lshoes, rshoes));
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> lshoes >> rshoes;

	for(int i = 0; i < lshoes; i++){
		std::cin >> ls[i];
	}
	for(int i = 0; i < rshoes; i++){
		std::cin >> rs[i];
	}

	std::sort(ls, ls + lshoes);
	std::sort(rs, rs + rshoes);

	int l = 0, r = 1e9;
	int best = 1e9;

	while(l <= r){
		int mid = (l + r) / 2;

		if(good(mid)){
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << best << '\n';
}