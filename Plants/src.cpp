#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int found[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, rooms;
    std::cin >> n >> rooms;
    
    for(int i = 0; i < rooms; i++){
        int temp;
        std::cin >> temp;
        found[temp]++;
    }
    
    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        
        int attempt = 0;
        for(int j = a; j <= b; j++){
            attempt += found[j];
        }
        
        std::cout << attempt << '\n'; 
    }   
}