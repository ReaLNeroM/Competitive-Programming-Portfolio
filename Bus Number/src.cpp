#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 19;
const ll maxbit = 1 << maxn;
std::string s;
ll n;
ll valid[maxbit];
ll dp[maxbit];
ll count[10];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s;
	n = s.size();
	for(ll i = 0; i < n; i++){
		count[s[i] - '0']++;
	}

	for(ll i = 0; i < (1 << n); i++){
		ll bit_for_j = 0;

		valid[i] = true;
		for(ll j = 0; j < 10; j++){
			if(count[j] and !((1 << bit_for_j) & i)){
				valid[i] = false;
				break;
			}
			bit_for_j += count[j];
		}
	}

	for(ll i = (1 << n) - 1; i >= 0; i--){
		dp[i] = valid[i];

		//add other
		ll running_sum = 0;

		for(ll j = 0; j < 10; j++){
			ll next_bit = running_sum + count[j];
			ll attempt_bit = running_sum;

			while(attempt_bit < next_bit and ((1 << attempt_bit) & i)){
				attempt_bit++;
			}

			if(attempt_bit < next_bit and (i != 0 or j != 0)){
				dp[i] += dp[i | (1 << attempt_bit)];
			}

			running_sum += count[j];
		}
	}

	std::cout << dp[0] << '\n';
}
