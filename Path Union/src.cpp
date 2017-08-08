#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll fill[maxn];
ll left[maxn];
ll start[maxn];
std::unordered_set<ll> s[64];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    n++;
    
    start[0] = 1;
    left[0] = 1;
    
    for(ll i = 1; i < n; i++){
        std::cin >> fill[i];
        left[i] = (1LL << i);
        start[i] = start[i - 1] + left[i - 1];
    }
    
    for(ll i = 1; i < n; i++){
    	for(ll j = 1; j <= i; j++){
    		if(left[j] > 0){
    			for(ll k = start[j]; k < start[j] + (1LL << j) and fill[i]; k++){
    				if(s[j].find(k) == s[j].end()){
    					s[j].insert(k);
    					
    					ll kcopy = k;
    					for(ll level = j + 1; level <= i; level++){
    						kcopy = kcopy * 2;
    						s[level].insert(kcopy);
    					}
    					
    					left[j]--;
    					fill[i]--;
    					std::cout << kcopy << '\n';
    				}
    			}
    		}
    	}
    }
}