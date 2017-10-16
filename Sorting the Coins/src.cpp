#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e5 + 1e2;
int used[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int res = 1;
	int search = n;

	std::cout << res << ' ';

	for(int i = 0; i < n; i++){
		int get;
		std::cin >> get;
		used[get] = true;

		while(used[search]){
			search--;
			res--;
		}
		res++;

		std::cout << res << ' ';
	}
}