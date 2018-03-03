#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    std::map<int, int> m;

    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    std::sort(val, val + n);

    if(val[0] == val[n - 1]){
    	std::cout << 0 << '\n';
    	return 0;
    }

    for(int i = 0; i < n; i++){
    	m[val[i]]++;
    }

    int res = maxn;
    int spaces = n - (*m.begin()).second;
    int need = n - (*m.rbegin()).second;
    int jumps = 0;

    for(int j = (*m.rbegin()).first; j + 20 > (*m.rbegin()).second; j--){
    	if(need <= spaces){
    	    res = std::min(res, jumps);
    	}
    	jumps += m[j];
    	need -= m[j - 1];
    	spaces += m[j] * 2;
    	m[j - 1] += m[j] * 2;
    	m.erase(m.lower_bound(j));
    }
    
    if(res == maxn){
        res = -1;
    }
    
    std::cout << res << '\n';
}