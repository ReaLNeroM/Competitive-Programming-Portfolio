#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Solution {
public:
    std::string bestAns = "";
    const ll mod = 101107157131LL;
    const ll base = 257;

    bool good(std::string& s, ll m){
        std::set<ll> ss;

        ll hash = 0LL;
        ll exp = 1LL;
        for(int i = 0; i < m; i++){
        	hash = (hash * base + s[i]) % mod;
        }
        for(int i = 0; i < m; i++){
        	exp = (exp * base) % mod;
        }
        ss.insert(hash);

        for(int i = m; i < s.size(); i++){
        	hash = (hash * base + s[i]) % mod;
        	hash -= exp * s[i - m];
        	hash %= mod;
        	if(hash < 0){
        		hash += (hash + 10LL * mod) % mod;
        	}

        	if(ss.find(hash) != ss.end()){
        		bestAns = s.substr(i - m + 1, m);
        		//get this bish
        		return true;
        	} else {
        		ss.insert(hash);
        	}
        }

        return false;
    }

    string longestDupSubstring(string S) {
        ll l = 1, r = S.size();

        while(l<=r){
            ll mid = (l+r)/2;

            if(good(S, mid)){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return bestAns;

    }
};
