#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 1; i < n; i++){
        int skip = false;
        do {
            std::cout << "Q 1 " << i + 1 << std::endl;
            
            std::cin >> skip;
        } while(!skip);
    }
    
    std::cout << "A" << '\n';
}