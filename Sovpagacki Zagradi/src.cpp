#include <bits/stdc++.h>
 
typedef long long ll;

const ll mod = 1000000000039;
const ll maxn = 1e6 + 1e2;

ll n;
std::string s;
std::unordered_map<ll, std::vector<ll>> m;
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> s;
    n = s.size();

    std::stack<char> open;
    std::stack<ll> open_hash;
    open_hash.push(1LL);

    for(ll i = 0; i < n; i++){
    	if(!open.empty() and open.top() == s[i]){
			m[open_hash.top()].push_back(i);
    		open.pop();
    		open_hash.pop();
    	} else {
    		open.push(s[i]);
    		open_hash.push((open_hash.top() * 31LL + (open.top() - 'a') + 1LL) % mod);
			m[open_hash.top()].push_back(i);
    	}

    }

    if(!open.empty()){
    	std::cout << -1 << '\n';
    	return 0;
    }

    std::string res = std::string(n, '(');

    for(ll i = 0; i < n; i++){
    	if(!open.empty() and open.top() == s[i]){
    		open.pop();
    		open_hash.pop();
    	} else {
    		open.push(s[i]);
    		open_hash.push((open_hash.top() * 31LL + (open.top() - 'a') + 1LL) % mod);
    		auto& v = m[open_hash.top()];
    		res[v[v.size() - 1]] = ')';
    		v.pop_back();
    	}
    }

    std::cout << res << '\n';
}
