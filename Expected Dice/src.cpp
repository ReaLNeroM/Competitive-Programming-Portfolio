#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int a[26];
int b[26];
int found[201];

int main(){
    std::ios::sync_with_stdio(false);
    
    for(int i = 0; i < 6; i++){
        std::cin >> a[i];
    }
    for(int i = 0; i < 6; i++){
        std::cin >> b[i];
    }
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            found[a[i] + b[j]]++;
        }
    }
    
    int most = 0;
    int res = 0;
    for(int i = 0; i <= 200; i++){
        if(most < found[i]){
            most = found[i];
            res = i;
        }
    }
    
    std::cout << res << '\n';
}