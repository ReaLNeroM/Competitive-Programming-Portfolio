#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static ll dp[31][31][31][31];
class Solution {
public:
    vector<int> v;
    int k;
    ll table[33];
    
    int mergeStones(vector<int>& stones, int K) {
        v = stones;
        k = K;

        int total = stones.size();
        while(total > 1){
            total -= (K - 1);
        }
        if(stones.size() == 1){
            return 0;
        }
        if(total != 1){
            return -1;
        }
        
        memset(dp, -1, sizeof(dp));
        
        memset(table, 0, sizeof(table));
        for(int i = 1; i <= stones.size(); i++){
            table[i] = table[i - 1] + stones[i - 1];
        }
        
        for(int depth = 1; depth >= 1; depth--){
			for(int len = 0; len <= v.size(); len++){
				for(int start = 0; start + len <= v.size(); start++){
					for(int left = 0; left <= k; left++){
            			int end = start + len;
            			if(start < end and left == 0){
							dp[start][end][left][depth] = 1e18;
							continue;
            			} else if(start + 1 >= end){
							dp[start][end][left][depth] = 0;
							continue;
						} else if(left == 1){
							dp[start][end][left][depth] = table[end] - table[start];
							continue;
						}

						ll& ans = dp[start][end][left][depth];
						ans = 1e18;
						ll sum = 0;

                        for(int i = start + 1; i <= end; i++){
							if(i == start){
								sum = 0;
							} else {
								sum = dp[start][i][k][depth];
							}

							ll othersum = 0;
							if(left == 2){
								othersum += table[end] - table[i];
							}
							ans = std::min(ans, sum + dp[i][end][left - 1][depth] + othersum + (table[i] - table[start]));
						}
            		}
            	}
            }
        }
        
        return dp[0][v.size()][K][1];
    }
};
