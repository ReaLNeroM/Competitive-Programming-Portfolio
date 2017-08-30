#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int prime[maxn];
int val[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, k;
    std::cin >> n >> k;

    std::fill(prime, prime + maxn, true);

    std::vector<int> v;
    for(int i = 2; i < maxn; i++){
    	if(prime[i]){
    		v.push_back(i);

    		if(i < 10000){
    			for(int j = i * i; j < maxn; j += i){
    				prime[j] = false;
    			}
    		}
    	}
    }

    k = n * (n - 1) / 2 - k;
    ll curr = 1;
    ll vpos = 1;

    for(int i = 0; i < n; i++){
    	if(n - i - 1 > k){
    		val[i] = curr * v[vpos];
    		vpos++;
    	} else {
    		val[i] = curr * v[vpos];
    		vpos++;
    	}
    }

    for(int i = 0; i < n; i++){
    	std::cout << val[i] << ' ';
    }
    std::cout << '\n';
}