#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    std::string s;
    std::cin >> s;
    
    int n = s.size();
        
    int left = n, right = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            left = std::min(left, i);
            right = std::max(right, i);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            int l = i, r = i;
            while(l > 1 and s[l - 1] == '0'){
                l--;
            }
            while(r + 1 < n and s[r + 1] == '0'){
                r++;
            }
            
            if(left < l or r < right){
                res = std::max(res, r - l + 1);
            } else {
                res = std::max(res, r - l);
            }
        }
    }

    std::cout << res;
}