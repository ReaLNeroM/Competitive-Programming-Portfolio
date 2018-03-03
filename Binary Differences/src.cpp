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
        if(val[i] == 0){
            val[i] = -1;
        }
    }
    
    int highest = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        curr += val[i];
        curr = std::max(curr, 0);
        highest = std::max(highest, curr);
    }
    
    int lowest = 0;
    curr = 0;
    for(int i = 0; i < n; i++){
        curr += val[i];
        curr = std::min(curr, 0);
        lowest = std::min(lowest, curr);
    }
    
    std::cout << highest - lowest + 1 << '\n';
}