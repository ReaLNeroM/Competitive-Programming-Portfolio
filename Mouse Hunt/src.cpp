#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int maxjmp = 20;
int skip[maxjmp][maxn];
int c[maxn];
int val[maxn];
bool tagged[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> c[i];
	}
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
		skip[0][i] = val[i];
	}

	for(int jump = 1; jump < 20; jump++){
		for(int i = 0; i < n; i++){
			skip[jump][i] = skip[jump - 1][skip[jump - 1][i]];
		}
	}

	ll res = 0;

	for(int i = 0; i < n; i++){
		int start = skip[19][i];

		if(tagged[start]){
			continue;
		}

		int minimum = c[start];
		tagged[start] = true;

		do {
			minimum = std::min(minimum, c[start]);
			start = val[start];
			tagged[start] = true;	
		} while(start != skip[19][i]);

		res += minimum;
	}

	std::cout << res << '\n';
}