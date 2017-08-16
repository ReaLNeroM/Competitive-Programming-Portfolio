#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int cop[maxn];
int final[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    std::multiset<std::vector<int>> m;
    
    int res = 0;
    for(int i = 0; i < n; i++){
        m.insert({val[i], i});
    }
    int currind = 0;
    
    while(!m.empty()){
        int frind = (*m.begin())[1];
        final[frind] = currind;
        currind++;
        m.erase(m.begin());
    }
    
    for(int i = 0; i < n; i++){
        res = std::max(res, i - final[i]);
    }

    std::cout << res + 1 << '\n';
    
}