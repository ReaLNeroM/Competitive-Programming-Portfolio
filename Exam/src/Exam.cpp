#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll max_board = 20000005;
const ll maxn = 3005;

//given a value, board returns how many pairs of two numbers give that sum
static ll board[max_board];
ll val[maxn];
pair<ll, ll> v[maxn];
ll res = 0;

ll ways(ll a, ll b){
	ll ans = 1;
	for(ll i = a - b + 1; i <= a; i++){
		ans *= i;
	}
	for(ll j = 1; j <= b; j++){
		ans /= j;
	}

	return ans;
}

int main(){
	ll n;
	cin >> n;

	for(ll i = 0; i < n; i++){
		cin >> val[i];
	}

	sort(val, val + n);

	ll size = 0;
	for(ll i = 0; i < n;){
		ll j;
		for(j = i; j < n; j++){
			if(val[i] != val[j]){
				break;
			}
		}

		v[size].first = val[i];
		v[size].second = j - i;
		size++;
		i = j;
	}

	//3 1 1 1
	//also board is filled
	for(ll j = 0; j < size; j++){
		ll r = 0;
		for(ll i = j + 1; i < size; i++){
			res += board[v[i].first - v[j].first] * ways(v[i].second, 3) * v[j].second;
			if(v[j].first * 3 == v[i].first){
				res += ways(v[i].second, 3) * ways(v[j].second, 3);
			}
			ll other = v[i].first - v[j].first - v[j].first;

			while(r <= j and v[r].first < other){
				r++;
			}

			if(r < j and v[r].first == other){
				res += v[r].second * ways(v[j].second, 2) * ways(v[i].second, 3);
			}
		}

		for(ll k = 0; k < j; k++){
			board[v[j].first + v[k].first] += v[k].second * v[j].second;
		}

		board[v[j].first + v[j].first] += ways(v[j].second, 2);
	}

	//2 2 1 1
	for(ll i = 0; i < size; i++){
		ll small_res = 0;
		ll under_ways = 0;
		ll r = i - 1;
		for(ll j = 0; j < i; j++){
			ll other = v[i].first - v[j].first;

			while(j <= r and other < v[r].first){
				r--;
			}
			if(r < j){
				break;
			} else if(r == j and other == v[r].first){
				small_res += ways(v[j].second, 2) * under_ways;
				small_res += ways(v[j].second, 4);
			} else if(other == v[r].first){
				small_res += v[j].second * v[r].second * under_ways;
				small_res += ways(v[j].second, 2) * ways(v[r].second, 2);
				under_ways += v[j].second * v[r].second;
			}
		}

		res += small_res * ways(v[i].second, 2);
	}


	cout << res;
}
