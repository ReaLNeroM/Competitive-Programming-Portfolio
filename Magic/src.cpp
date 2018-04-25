#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

const int maxn = 1e5 + 1e2;
int val[maxn];
bool used[256];
ll res = 0;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int distinct = 0;

	for(char i : s){
		if(!used[i]){
			distinct++;
		}

		used[i] = true;
	}

	for(int i = 0; i + distinct <= s.size(); i++){
		std::memset(used, 0, sizeof(used));

		bool good = true;

		for(int j = i; j < i + distinct; j++){
			if(used[s[j]]){
				good = false;
				break;
			}

			used[s[j]] = true;
		}

		if(!good){
			continue;
		}

		val[i + distinct] = val[i] + 1;

		std::cout << i + 1 << ' ' << val[i + distinct] << '\n';
		res += val[i + distinct];
		res %= mod;
	}

	std::cout << res << '\n';
}