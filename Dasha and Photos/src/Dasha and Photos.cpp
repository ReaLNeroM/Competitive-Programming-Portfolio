#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e3 + 5;
const ll maxk = 3e5;
static ll sy[maxk], sx[maxk], ey[maxk], ex[maxk];
static char c[maxk];
static char s[maxn][maxn];
static ll add[maxn][maxn][26];
static ll cost[maxn][maxn][26];
static ll costdefault[maxn][maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll y, x, special;
	cin >> y >> x >> special;

	for(ll i = 0; i < y; i++){
		for(ll j = 0; j < x; j++){
			cin >> s[i][j];
		}
	}
	
	for(ll i = 0; i < special; i++){
		cin >> sy[i] >> sx[i] >> ey[i] >> ex[i];
		cin >> c[i];

		sx[i]--, sy[i]--, ex[i]--, ey[i]--;
		for(ll j = sy[i]; j <= ey[i]; j++){
			add[j][sx[i]][c[i] - 'a']++;
			add[j][ex[i] + 1][c[i] - 'a']--;
		}
	}

	for(ll i = 0; i < y; i++){
		ll sum_part[26];
		for(ll k = 0; k < 26; k++){
			sum_part[k] = 0;
		}
		ll sum = special;
		for(ll j = 0; j < x; j++){
			for(ll k = 0; k < 26; k++){
				sum_part[k] += add[i][j][k];
				sum -= add[i][j][k];
			}
			sum_part[s[i][j] - 'a'] += sum;
			ll dec = 0;
			ll big_sum = 0;
			for(int k = 0; k < 26; k++){
				cost[i][j][k] += big_sum;
				dec += sum_part[k];
				big_sum += dec;
			}
			dec = 0;
			big_sum = 0;
			for(int k = 25; k >= 0; k--){
				cost[i][j][k] += big_sum;
				dec += sum_part[k];
				big_sum += dec;
			}
			sum_part[s[i][j] - 'a'] -= sum;
		}
	}

	for(ll i = 0; i < y; i++){
		for(ll j = 0; j < x; j++){
			costdefault[i][j] = cost[i][j][s[i][j] - 'a'];
			if(i != 0){
				costdefault[i][j] += costdefault[i - 1][j];
			}
			if(j != 0){
				costdefault[i][j] += costdefault[i][j - 1];
			}
			if(i != 0 and j != 0){
				costdefault[i][j] -= costdefault[i - 1][j - 1];
			}
		}
	}
	
	for(ll i = 0; i < y; i++){
		for(ll j = 0; j < x; j++){
			for(ll k = 0; k < 26; k++){
				if(i != 0){
					cost[i][j][k] += cost[i - 1][j][k];
				}
				if(j != 0){
					cost[i][j][k] += cost[i][j - 1][k];
				}
				if(i != 0 and j != 0){
					cost[i][j][k] -= cost[i - 1][j - 1][k];
				}
			}
		}
	}
	
	ll res = 1e18;
	for(ll i = 0; i < special; i++){
		ll sum = 0;
		sum += costdefault[y - 1][x - 1];
		sum -= costdefault[ey[i]    ][ex[i]    ];
		if(sx[i] - 1 >= 0){
			sum += costdefault[ey[i]    ][sx[i] - 1];
		}
		if(sy[i] - 1 >= 0){
			sum += costdefault[sy[i] - 1][ex[i]    ];
		}
		if(sy[i] - 1 >= 0 and sx[i] - 1 >= 0){
			sum -= costdefault[sy[i] - 1][sx[i] - 1];
		}

		sum += cost[ey[i]    ][ex[i]    ][c[i] - 'a'];
		if(sx[i] - 1 >= 0){
			sum -= cost[ey[i]    ][sx[i] - 1][c[i] - 'a'];
		}
		if(sy[i] - 1 >= 0){
			sum -= cost[sy[i] - 1][ex[i]    ][c[i] - 'a'];
		}
		if(sy[i] - 1 >= 0 and sx[i] - 1 >= 0){
			sum += cost[sy[i] - 1][sx[i] - 1][c[i] - 'a'];
		}
		res = min(res, sum);
	}

	cout << res;
}
