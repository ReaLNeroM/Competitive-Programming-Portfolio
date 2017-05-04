#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int res = 0;
	int pos = 1;
	int state = 0;
	for(int i = 0; i < n - 1; i++){
		if(state == 0){
			pos = n + 1 - pos;
		} else {
			pos = n + 2 - pos;
			res++;
		}
		state = !state;
	}

	std::cout << res;
}