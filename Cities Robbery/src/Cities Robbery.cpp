#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 100;
pair<ll, ll> cc[maxn];
ll coord[maxn];
ll money[maxn];
ll sum[maxn];
ll res = 0;
ll n, start, dist;
ll lowestbigger = maxn + 1;

void binary(ll l, ll r, bool side){
	while(l <= r){
		ll mid = (l + r) / 2;

		if(abs(coord[mid] - start) <= dist){
			if(side == 0){
				r = mid - 1;
				res = max(res, sum[lowestbigger - 1] - sum[mid - 1]);
			} else {
				l = mid + 1;
				res = max(res, sum[mid] - sum[lowestbigger - 1]);
			}
		} else {
			if(side == 0){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> start >> dist;

    for(ll i = 1; i <= n; i++){
    	cin >> cc[i].first >> cc[i].second;
    }
    sort(cc + 1, cc + n + 1);
    for(ll i = 1; i <= n; i++){
    	coord[i] = cc[i].first;
    	money[i] = cc[i].second;
        if(coord[i] >= start){
        	lowestbigger = min(lowestbigger, i);
        }
    }
    for(ll i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + money[i];
    }

    binary(1, lowestbigger - 1, 0);
    binary(lowestbigger, n, 1);

    ll sweep = lowestbigger - 1;
    for(ll i = 1; i < lowestbigger; i++){
    	while(sweep <= n - 1 and (start - coord[i]) + (coord[sweep + 1] - start) + min((start - coord[i]), (coord[sweep + 1] - start)) <= dist){
    		sweep++;
    		res = max(res, sum[sweep] - sum[i - 1]);
    	}
    }

    cout << res;
}
