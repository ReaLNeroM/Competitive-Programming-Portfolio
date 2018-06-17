#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
int val[maxn];
int found[maxn];
int need[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, alphabet, important;
	std::cin >> n >> alphabet >> important;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < important; i++){
		int b, q;
		std::cin >> b >> q;

		need[b] = q;
	}

	int res = maxn;

	int left = important;
	int l = 0, r = -1;
	while(l < n - 1){
		while(r < n - 1 and left){
			r++;
			found[val[r]]++;

			if(found[val[r]] == need[val[r]]){
				left--;
			}
		}

		if(left == 0){
			res = std::min(res, r - l + 1);
		}

		if(found[val[l]] == need[val[l]]){
			left++;
		}
		found[val[l]]--;
		l++;
	}

	if(res == maxn){
		std::cout << "impossible\n";
	} else {
		std::cout << res << '\n';
	}
}
