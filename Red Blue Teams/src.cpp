#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    int r, b;
    int change;
    std::cin >> r >> change;
    
    b = n - r;
    
    int tr = r, tb = b, tchange = change;
    if(tr > tchange){
        tr -= tchange;
        tb += tchange;
    } else {
        tb += tr;
        tchange -= tr;
        tr = tchange;
    }
    std::cout << tr << ' ';
    
    tr = r, tb = b, tchange = change;
    
    if(tb > tchange){
        tb -= tchange;
        tr += tchange;
    } else {
        tr += tb;
        tchange -= tb;
        tr -= tchange;
    }
    
    std::cout << tr << '\n';
}