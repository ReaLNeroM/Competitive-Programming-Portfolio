#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll res[maxn];
std::map<ll, ll> increment, decrement;
std::set<ll> points;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    
    for(ll i = 0; i < n; i++){
    	ll a, b;
    	std::cin >> a >> b;

    	points.insert(a);
    	points.insert(b);

    	increment[a]++;
    	decrement[b]++;
    }

    ll open_intervals = 0;

    for(auto ite = points.begin(); ite != points.end(); ite++){
    	if(ite != points.begin()){
    		auto sec = ite;
    		sec--;
    		res[open_intervals] += *ite - *(sec) - 1;
    	}

    	open_intervals += increment[*ite];
    	res[open_intervals] += 1;
    	open_intervals -= decrement[*ite];
    }

    for(ll i = 1; i <= n; i++){
    	std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}
