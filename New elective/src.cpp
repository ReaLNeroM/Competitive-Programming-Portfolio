#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5e5 + 1e2;
int val[maxn];
int sorted[maxn];
int next[maxn];
bool done[maxn];
int get[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		sorted[i] = val[i];
	}

	std::fill(get, get + n, true);

	std::sort(sorted, sorted + n);
	sorted[n] = 1e9;
	
	for(int i = 0; i < n; i++){
		next[sorted[i]] = sorted[i + 1];
	}

	for(int i = 0; i < n - 1; i++){
		if(next[val[i]] == val[i + 1] and !done[val[i]] and get[i]){
			done[val[i]] = true;
			int l = i, r = i;

			while(l > 0 and (next[val[l - 1]] == val[l] or val[l - 1] == val[l])){
				l--;
				get[l] = false;
			}
			while(r < n - 1 and (next[val[r]] == val[r + 1] or val[r] == val[r + 1])){
				r++;
				get[r] = false;
			}

			std::cout << l << ' ' << r << std::endl;
		}
	}

	for(int i = 0; i < n - 1; i++){
		if(val[i] == val[i + 1] and get[i]){
			get[i] = false;
		}
	}

	int res = 0;

	for(int i = 0; i < n; i++){
		res += get[i];
	}

	std::cout << res;
}