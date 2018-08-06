#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);

    ll n, m;
    std::cin >> n >> m;

    ll left = m;
    for(ll i = 0; i < n; i++){
 		std::cin >> val[i];

 		ll page = 0;

 		if(val[i] > 0 and left <= val[i]){
 			val[i] -= left;
 			left = m;
 			page++;
 		}

 		if(left <= val[i]){
 			ll x = val[i] / m;
 			page += x;

 			left += m * x - val[i];
 			val[i] = 0;
 		}

 		left -= val[i];

 		std::cout << page << ' ';
    }
}
