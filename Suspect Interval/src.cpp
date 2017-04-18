#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    sort(val, val + n);
    
    int res = 0;
    
    for(int i = 0; i < n; i++){
        int l, r;
        if(i == 0){
            l = 1;
        } else {
            l = val[i - 1] + 1;
        }
        
        if(i == n - 1){
            r = 100000;
        } else {
            r = val[i + 1] - 1;
        }
        res = std::max(res, r - l + 1)
    }
    std::cout << res;
}