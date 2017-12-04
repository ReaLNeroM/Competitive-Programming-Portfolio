#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    for(int i = 0; i < n; i++){
        bool found = false;
        
        for(int j = 0; j < n; j++){
            if(i != j and s[i] == s[j]){
                found = true;
                break;
            }
        }
        
        if(!found){
            std::cout << s[i];
            return 0;
        }
    }
    
    std::cout << -1 << '\n';
}