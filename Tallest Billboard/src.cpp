class Solution {
public:
    const static __int128 bits = 125;
    __int128 dp[2501 / bits + bits + 1][2501 + bits];
    
    int tallestBillboard(vector<int>& rods) {
        dp[0][0] = 1;
        
        __int128 unit = 1;
        for(int i = 0; i < rods.size(); i++){
            for(__int128 j = 2500 / bits; j >= 0; j--){
                for(__int128 k = 2500; k >= 0; k--){
                    __int128 offset = rods[i] % bits;
                    
                    __int128 aa = dp[j][k];
                    
                    if(j * bits + rods[i] <= 2500){
                        dp[j + rods[i] / bits][k]     |= (aa << offset);
                        dp[j + rods[i] / bits][k]     &= ((unit << bits) - 1);
                        dp[j + rods[i] / bits + 1][k] |= (aa >> (bits - offset));
                        dp[j + rods[i] / bits + 1][k] &= ((unit << bits) - 1);
                    }
                    if(k + rods[i] <= 2500){
                        dp[j][k + rods[i]] |= aa;
                    }
                }
            }
        }
        
        for(__int128 i = 2500 / bits; i >= 0; i--){
            for(__int128 ind = i * bits + bits - 1, j = (unit << (bits - 1)); j >= 1; j /= 2LL, ind--){
                if(j & dp[i][ind]){
                    return ind;
                }
            }
        }
    }
};