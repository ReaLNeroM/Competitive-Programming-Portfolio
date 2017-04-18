#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
ll val[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    ll sum = 0;
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
        sum += val[i];
    }
    
    for(int i = 0; i < n; i++){
        if(sum - (val[i] * 2) == 0){
            std::cout << i + 1 << std::endl;
            return 0;
        }   
    }
    
    std::cout << -1;   
}