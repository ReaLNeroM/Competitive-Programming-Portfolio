#include <iostream>

using namespace std;
typedef long long ll;

static ll dp[1 << 20];
ll power[32];

ll find(ll bitset) {
	if(bitset >= (1 << 20) or dp[bitset] == -1){
		ll size = -1;
		for(ll i = 1; i <= bitset; i *= 2){
			size++;
		}

		bool c[size];
		for (ll i = 0; i < size; i++) {
			c[size - i - 1] = (bitset & (1 << i)) != 0;
		}

		ll first = true, second = true;
		for (ll i = 0; i < size; i++) {
			if(c[i] != i % 2){
				first = false;
			} else if(c[i] == i % 2){
				second = false;
			}
		}

		ll res = 50;
		if ((first or second) and size % 2 == 0) {
			res = 1;
		} else if (size > 2) {
			ll prefix[size], suffix[size];
			prefix[0] = c[0], suffix[size - 1] = c[size - 1];

			for(ll i = 1; i < size; i++){
				prefix[i] = prefix[i - 1] * 2 + c[i];
			}
			for(ll i = size - 2; i >= 0; i--){
				suffix[i] = suffix[i + 1] * 2 + c[i];
			}

			for(ll i = 0; i < size - 1; i++){
				ll bit = 0;
				for(ll j = i; j < size - 1; j++){
					bit += c[j];

					if((j - i) % 2 == 1){
						ll otherbit = 0;
						if(i != 0){
							otherbit += prefix[i - 1] * power[size - j - 1];
						}
						otherbit += suffix[j + 1];


						ll attempt = find(otherbit + power[size - (j - i + 1)]);
						if(res > attempt){
							attempt += find(bit + power[j - i + 1]);
							if(res > attempt){
								res = attempt;
							}
						}
					}

					bit *= 2;
				}
			}
		}

		if(bitset < (1 << 20)){
			dp[bitset] = res;
		}

		return res;
	} else {
		return dp[bitset];
	}
}
int main() {
	ios::sync_with_stdio(false);

	for(ll i = 0; i < 32; i++){
		power[i] = 1 << i;
	}
	dp[0] = 50;
	dp[1] = 50;
	dp[2] = 50;
	dp[3] = 50;

	for (ll i = 4; i < (1 << 20); i++) {
		dp[i] = -1;
	}

	int cases;
	cin >> cases;
	for(int test = 0; test < cases; test++){
		string str;
		cin >> str;

		ll inp = 1;
		for(int i = 0; i < str.length(); i++){
			inp *= 2;
			inp += (str[i] == 'M');
		}

		int res = find(inp);
		if(res >= 50){
			cout << -1 << endl;
		} else {
			cout << res << endl;
		}
	}
	return 0;
}
