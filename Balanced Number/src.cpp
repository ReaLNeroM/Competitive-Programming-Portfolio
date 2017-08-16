#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;
int app[256];

int main(){
    std::ios::sync_with_stdio(false);
    

    std::string s;
    std::cin >> s;
    
    for(char i : s){
        app[i]++;
    }
    
    for(int i = '1'; i <= '9'; i++){
        if(app[i] != app[i - 1]){
            std::cout << 0;
            return 0;
        }
    }
    
    std::cout << 1;
}