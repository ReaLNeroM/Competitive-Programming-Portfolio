#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 205;
int val[maxn][maxn];
int prefsum[maxn][maxn];
int blocksum[maxn][maxn];
int besth[maxn], bestv[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int y, x, k;
    std::cin >> y >> x >> k;
    
    int zeroes_sum = 0;

    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= x; j++){
            std::cin >> val[i][j];
            zeroes_sum += 1 - val[i][j];
        }
    }
    
    for(int i = 0; i <= y; i++){
    	for(int j = 0; j <= x; j++){
    		if(i == 0 or j == 0){
    			prefsum[i][j] = 0;
    		} else{
    			prefsum[i][j] = val[i][j] + prefsum[i - 1][j] 
    									  + prefsum[i][j - 1] 
    									  - prefsum[i - 1][j - 1];
    		}
    	}
    }

    for(int i = 1; i + k <= y + 1; i++){
    	for(int j = 1; j + k <= x + 1; j++){
    		blocksum[i][j] = prefsum[i + k - 1][j + k - 1] - prefsum[i - 1][j + k - 1] 
    									   				   - prefsum[i + k - 1][j - 1] 
    													   + prefsum[i - 1][j - 1];
    	}
    }

    for(int i = 1; i + k <= y + 1; i++){
    	for(int j = 1; j + k <= x + 1; j++){
    		besth[i] = std::max(besth[i], blocksum[i][j]);
    		bestv[j] = std::max(bestv[j], blocksum[i][j]);
    	}
    }

	int res = 0;
    for(int i = 1; i + k <= y + 1; i++){
    	for(int j = 1; j + k <= x + 1; j++){
    		int other_block = 0;

    		for(int l = 1; l + k <= i; l++){
    			other_block = std::max(other_block, besth[l]);
    		}
    		for(int l = 1; l + k <= j; l++){
    			other_block = std::max(other_block, bestv[l]);
    		}
    		for(int l = i + k; l + k <= y + 1; l++){
    			other_block = std::max(other_block, besth[l]);
    		}
    		for(int l = j + k; l + k <= x + 1; l++){
    			other_block = std::max(other_block, bestv[l]);
    		}

    		for(int l = i; l < i + k and l + k <= y + 1; l++){
    			for(int m = j; m < j + k and m + k <= x + 1; m++){
    				other_block = std::max(other_block, blocksum[l][m] - prefsum[i + k - 1][j + k - 1] 
    																   + prefsum[l - 1][j + k - 1] 
    																   + prefsum[i + k - 1][m - 1] 
    																   - prefsum[l - 1][m - 1]);
    			}
    		}

    		for(int l = i + 1; l < i + k and l + k <= y + 1; l++){
    			for(int m = j - 1; m + k > j and m >= 1; m--){
    				other_block = std::max(other_block, blocksum[l][m] - prefsum[i + k - 1][m + k - 1]
    																   + prefsum[l - 1][m + k - 1]
    																   + prefsum[i + k - 1][j - 1]
    																   - prefsum[l - 1][j - 1]);
    			}
    		}

    		res = std::max(res, other_block + blocksum[i][j]);
    	}
    }

    std::cout << zeroes_sum + res << '\n';
}