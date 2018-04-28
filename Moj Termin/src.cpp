#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 1e3 + 1e2;
int val[maxn];
int dp[maxn];
 
int main(){
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
 
    for(int i = 0; i < n; i++){
        std::string c;
        std::cin >> c;

        if(c == "N"){
            val[i] = -1;
        } else {
            std::stringstream ostr;
            ostr << c;
            ostr >> val[i];
        }
    }
 
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = 0;
        int found_expected = -1;
        for(int j = i; j < n; j++){
            int size = j - i + 1;
 
            if(val[j] != -1 and found_expected != -1 and found_expected != val[j]){
                break;
            } else if(found_expected == -1){
                found_expected = val[j];
            }
        
            if(found_expected == -1 or found_expected == size){
                dp[i] += dp[j + 1];
                dp[i] = std::min(dp[i], 2);
            }
        }
 
        dp[i] = std::min(dp[i], 2);
    }
 
    if(dp[0] == 1){
        std::cout << "DA\n";
    } else {
        std::cout << "NE\n";
    }
}