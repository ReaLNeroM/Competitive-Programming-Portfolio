#include <bits/stdc++.h>

typedef long long ll;

const int maxy = 1e5 + 1e2;
std::vector<char> val[maxy];
std::vector<int> cost[maxy];

int main(){
    std::ios::sync_with_stdio(false);

    int y, x, k;
    std::cin >> y >> x >> k;
    
    for(int i = 0; i < y; i++){
        val[i].resize(x);
        cost[i].resize(x);
        
        for(int j = 0; j < x; j++){
            std::cin >> val[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x / 2; j++){
            if(val[i][j] == val[i][x - 1 - j]){
                cost[i][j] = 2;
            } else {
                cost[i][j] = 1;
                res += 1;
            }
        }
    }

    std::vector<int> per_column;
    for(int j = 0; j < x / 2; j++){
        int curr = 0;
        for(int i = 0; i < y / 2; i++){
            char a = val[i][j];
            char b = val[i][x - 1 - j];
            char c = val[y - 1 - i][j];
            char d = val[y - 1 - i][x - 1 - j];
            
            if(a != c and a != d and b != c and b != d){
            	curr += std::min(cost[i][j], cost[y - 1 - i][j]);
            }
        }
        per_column.push_back(curr);
    }
    
    std::sort(per_column.begin(), per_column.end());
    
    for(int i = 0; i < k / 2; i++){
        res += per_column[i];
    }
    
    per_column.push_back(1000000000);
    if(x % 2 == 1 and k % 2 == 1){
        int curr = 0;
        for(int i = 0; i < y / 2; i++){
            if(val[i][x / 2] != val[y - 1 - i][x / 2]){
                curr += 1;
            }  
        }
        
        if(k / 2 < per_column.size()){
            res += std::min(curr, per_column[k / 2]);
        } else {
            res += curr;
        }
    } else if(k % 2 == 1){
        res += per_column[k / 2];
    }
    
    std::cout << res << '\n';
}