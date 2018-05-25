#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll length[maxn];
ll limit[maxn];
std::multimap<double, int> m;
double res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n, x;
    std::cin >> n >> x;
    
    for(ll i = 0; i < n; i++){
        std::cin >> length[i];
    }
    for(ll i = 0; i < n; i++){
    	std::cin >> limit[i];
    }

    for(ll i = 0; i < n; i++){
    	res += length[i] / (double) limit[i];

    	double change = (length[i] / (double) limit[i]) - (length[i] / (double) (limit[i] + 1));

    	m.insert({change, i});
    }

    for(ll i = 0; i < x; i++){
    	double change = m.rbegin()->first;
    	ll ind = m.rbegin()->second;
    	m.erase(--m.end());

    	res -= change;
    	limit[ind]++;

    	double new_change = (length[ind] / (double) limit[ind]) - (length[ind] / (double) (limit[ind] + 1));
    	m.insert({new_change, ind});
    }

    std::cout.precision(9);
    std::cout << std::fixed << res << '\n';
}