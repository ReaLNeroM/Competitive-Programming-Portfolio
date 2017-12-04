#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll word[maxn];
ll pref[maxn];
ll next[maxn];
ll cost[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);

    ll n, w, h;
    std::cin >> n >> w >> h;
    w++;

    for(ll i = 0; i < n; i++){
    	word[i] = 1;
        // std::cin >> word[i];
        word[i]++;

        pref[i + 1] = pref[i] + word[i];
    }

    std::fill(next, next + maxn, -1);

    ll pos = 0;

    while(next[pos] == -1){
    	ll left_w = w % pref[n];
    	if(left_w + pref[n] <= w){
    		left_w += pref[n];
    	}

    	ll ind = pos;

		cost[ind] = (w - left_w) / pref[n];

    	if(pref[n] - pref[pos] + word[0] <= left_w){
    		left_w -= pref[n] - pref[pos];
    		cost[ind]++;
    		pos = 0;
    	}

        ll l = pos + 1;
        ll r = n;
        ll last = pos;

        while(l <= r){
            ll mid = (l + r) / 2;

            if(pref[mid] - pref[pos] <= left_w){
            	l = mid + 1;
            	last = mid;
            } else {
            	r = mid - 1;
            }
        }

        if(last == n){
        	cost[ind]++;
        }

    	next[ind] = last % n;
    	pos = next[ind];
    }

    ll start_cycle = pos;

    pos = 0;
    while(pos != start_cycle){
    	res += cost[pos];
    	pos = next[pos];
    }

    ll loop_size = 0, loop_cost = 0;
    for(ll i = 0; true; i++){
    	if(i != 0 and pos == start_cycle){
    		loop_size = i;
    		break;
    	}

    	loop_cost += cost[pos];
    	pos = next[pos];
    }

    for(ll i = 0; i < h % loop_size; i++){
    	res += cost[pos];
    	pos = next[pos];
    }
    
    res += (h / loop_size) * loop_cost;

    if(pos == 0){
    	res--;
    }

    std::cout << res + 1;
}
