#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> dp;
    vector<string> A;
    
    int dfs(int pos, int lastAdd){
        if(pos >= A[0].size()){
            return 0;
        }
        
        if(dp[pos][lastAdd] != -1){
            return dp[pos][lastAdd];
        }
        
        
        int& ans = dp[pos][lastAdd];
        ans = dfs(pos + 1, lastAdd) + 1;
        
        bool good = true;
        
        for(int i = 0; i < A.size(); i++){
            if(lastAdd != 0 and A[i][pos] > A[i][lastAdd - 1]){
                good = false;
            }
        }
        
        if(lastAdd == 0 or good){
            ans = std::min(ans, dfs(pos + 1, pos + 1));
        }
        
        return ans;
    }
    int minDeletionSize(vector<string>& b) {
        A = b;
        dp.resize(101, std::vector<int>(101, -1));
        
        return dfs(0, 0);
    }
};