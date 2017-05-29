#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        int value_written;
        std::cin >> value_written;
        val[value_written] = true;
    }

    for(int i = 1; i + k - 1 <= 1000; i++){
    	int needed = k;
    	for(int j = i; j <= i + k - 1; j++){
    		if(val[j]){
    			needed--;
    		}
    	}

    	if(needed <= m){
    		res++;
    	}
    }

    std::cout << res;
}