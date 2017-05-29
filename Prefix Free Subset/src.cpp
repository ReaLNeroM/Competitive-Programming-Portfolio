#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
const ll mod = 20000000000000003;
ll res = maxn;
int n, k;
std::unordered_set<ll> last_used[100];
int curr_sweep = 0;
std::string s[maxn];
std::vector<ll> hash[maxn];

bool cmp(std::string const &a, std::string const &b) {
	return a.size() < b.size();
}

int found(int max_length){
	int subsetable = 0;

	for(int i = n - 1; i >= 0; i--){
		if(s[i].size() <= max_length and last_used[curr_sweep].find(hash[i][s[i].size() - 1]) == last_used[curr_sweep].end()){
			subsetable++;
			if(subsetable >= k){
				curr_sweep++;
				return true;
			}

			for(int j = 0; j <= s[i].size() - 1; j++){
				last_used[curr_sweep].insert(hash[i][j]);
			}
		}
	}

	curr_sweep++;
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		std::cin >> s[i];
	}

	for(int i = 0; i < 100; i++){
		last_used[i].clear();
	}

	std::sort(s, s + n, cmp);

	for(int i = 0; i < n; i++){
		hash[i].resize(s[i].size());

		hash[i][0] = s[i][0] - 'a' + 1;
		for(int j = 1; j < s[i].size(); j++){
			hash[i][j] = hash[i][j - 1] * 31LL + (s[i][j] - 'a' + 1);
			hash[i][j] %= mod;
		}
	}

	int l = 1, r = maxn;

	while(l <= r){
		int mid = (l + r) / 2;

		if(found(mid)){
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}

	if(res == maxn){
		res = -1;
	}

	std::cout << res << std::endl;
}