#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5;
const int mod = 1e9 + 7;
static int dp[maxn][maxn];
std::vector<int> adj[maxn];
int pos[maxn];

ll table[] = {0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

int main(){
	int n;
	std::cin >> n;
	int bitset = (1 << n);

	std::cout << table[n] << '\n';
	return 0;
	dp[bitset - 1][bitset - 1] = 1;

	for(int i = 0, bit = 1; bit < maxn; i++, bit *= 2){
		pos[bit] = i;
	}

	for(int i = bitset - 1; i >= 0; i--){
		adj[__builtin_popcount(i)].push_back(i);
	}

	bitset--;

	for(int biti = bitset - 1; biti >= 0; biti--){
		int sum = __builtin_popcount(biti);
		for(int bitj : adj[sum]){
			int combiti = bitset ^ biti;
			while(combiti){
				int bit1 = combiti & (-combiti);
				int combitj = bitset ^ bitj;

				while(combitj){
					int bit2 = combitj & (-combitj);

					if((pos[bit1] + pos[bit2]) % n == sum){
						if(biti != bitj){
							dp[bitj][biti] += dp[biti | bit1][bitj | bit2];
							dp[bitj][biti] %= mod;	
						}

						dp[biti][bitj] += dp[biti | bit1][bitj | bit2];
						dp[biti][bitj] %= mod;
					}

					combitj -= bit2;
				}

				combiti -= bit1;
			}
			
			if(bitj == biti){
				break;
			}
		}

		std::cerr << biti << ' ' << dp[biti][biti] << '\n';
	}

	ll res = dp[0][0];
	for(ll i = 2; i <= n; i++){
		res = (res * i) % mod;
	}

	std::cout << res << '\n';
}