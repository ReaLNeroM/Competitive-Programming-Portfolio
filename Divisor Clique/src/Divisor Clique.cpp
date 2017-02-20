#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 100;
const ll worst = -1e18;
ll n;
ll val[maxn];
ll dp[maxn][4];
ll res = 0;

ll findx(ll pos, ll state){
	if(dp[pos][state] == worst){
		ll &res = dp[pos][state];
		if(pos == n){
			if(state >= 3){
				res = 0;
			} else {
				res = worst;
			}
		} else {
			if(state == 0){
				res = max(findx(pos + 1, 0), findx(pos + 1, 1) + val[pos]);
			} else if(state == 1){
				res = max(findx(pos + 1, 2), findx(pos + 1, 1) + val[pos]);
			} else if(state == 2){
				res = max(findx(pos + 1, 2), findx(pos + 1, 3) + val[pos]);
			} else if(state == 3){
				res = max(0LL              , findx(pos + 1, 3) + val[pos]);
			}
		}
	}

	return dp[pos][state];
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n;

    for(ll i = 0; i <= n; i++){
    	for(ll j = 0; j < 4; j++){
    		dp[i][j] = worst;
    	}
    }

    for(auto &i : val)
		cin >> i;

    for(ll i = 0; i < n; i++){
    	cin >> val[i];
    }

    cout << findx(0, 0);
}
