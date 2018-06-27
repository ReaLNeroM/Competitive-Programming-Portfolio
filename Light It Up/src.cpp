#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll val[maxn];
ll odd[maxn];
ll even[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n, m;
    std::cin >> n >> m;
    
    val[0] = 0;
    for(ll i = 1; i <= n; i++){
        std::cin >> val[i];
    }
    val[n + 1] = m;

    for(ll i = 1; i <= n + 1; i++){
    	if(i % 2 == 1){
    		odd[i] = odd[i - 1] + val[i] - val[i - 1];
    		even[i] = even[i - 1];
    	} else {
    		even[i] = even[i - 1] + val[i] - val[i - 1];
    		odd[i] = odd[i - 1];
    	}
    }

    res = odd[n + 1];
    for(ll i = 0; i <= n; i++){
    	if(val[i] + 1 == val[i + 1]){
    		continue;
    	}

    	ll attempt = 0;
    	attempt = odd[i] + even[n + 1] - even[i + 1] + val[i + 1] - val[i] - 1;

    	res = std::max(res, attempt);
    }


    std::cout << res << '\n';
}