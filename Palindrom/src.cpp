#include <bits/stdc++.h>

typedef long long ll;

std::string s;

ll pow(ll a, ll e){
	ll res = 1;
	for(ll i = 0; i < e; i++){
		res *= a;
	}

	return res;
}

ll dfs(ll start, ll end, bool below){
	ll sum = 0;

	if(below == true){
		return pow(10, end - start);
	}

	if(start == end){
		return 0;
	}

	if(start == 0 and s[start] > '1'){
		sum += (s[start] - '1') * dfs(start + 1, end, true);
	} else if(start != 0 and s[start] > '0'){
		sum += (s[start] - '0') * dfs(start + 1, end, true);
	}

	sum += dfs(start + 1, end, false);

	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);

	while(true){
		std::cin >> s;

		ll sum = 0;
		for(ll i = 1; i < s.size(); i++){
			ll changes_allowed = (i + 1) / 2;

			sum += 9 * pow(10, changes_allowed - 1);
		}

		std::string v = s;

		for(int i = 0; i <= (int) v.size() - i - 1; i++){
			v[(int) v.size() - 1 - i] = v[i];
		}

		if(s >= v){
			sum++;
		}

		std::cout << sum + dfs(0, ((ll) s.size() + 1) / 2, false);

		return 0;
	}
}
