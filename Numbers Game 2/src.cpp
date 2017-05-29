#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }

    for(int i = 0; i < n - 1; i++){
    	if(val[i] % 10 != val[i + 1] / 10){
    		res++;
    	}
    }

    std::cout << res;
}