#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll res[maxn];
ll size[maxn];
ll arrival[maxn];
std::map<ll, ll> start_fuel;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    	
    for(ll i = 0; i < n; i++){
		std::cin >> size[i] >> arrival[i];

		std::map<ll, ll>::iterator ite;

		do {
			ite = start_fuel.upper_bound(arrival[i]);

			if(ite == start_fuel.end() or ite->second >= arrival[i] + size[i]){
				start_fuel[arrival[i] + size[i]] = arrival[i];
				ite = start_fuel.find(arrival[i] + size[i]);
				if(start_fuel.lower_bound(arrival[i])->first == arrival[i]){
					ite->second = start_fuel.lower_bound(arrival[i])->second;
					start_fuel.erase(start_fuel.find(arrival[i]));
				}
				res[i] = arrival[i] + size[i];
				break;
			} else if(ite->second > arrival[i]){
				size[i] -= ite->second - arrival[i];
				ite->second = arrival[i];
				if(start_fuel.lower_bound(arrival[i])->first == arrival[i]){
					ite->second = start_fuel.lower_bound(arrival[i])->second;
					start_fuel.erase(start_fuel.find(arrival[i]));
				}
				arrival[i] = ite->first;
			} else {
				arrival[i] = ite->first;
			}
		} while(true);
    }

    for(ll i = 0; i < n; i++){
    	std::cout << res[i] << '\n';
    }
}