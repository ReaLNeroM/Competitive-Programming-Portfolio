#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 40005;
const int max_block = 205;
int block[maxn][max_block];
int val[maxn];
int block_size;
int n;

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
		std::cin >> val[i];
    }

    block_size = std::sqrt(n);

    for(int i = 0, l = 0, r = block_size - 1; r < n; i++, l += block_size, r += block_size){
    	for(int j = 1; j <= maxn; j++){
    		block[j][i] = 
    	}
    }
}