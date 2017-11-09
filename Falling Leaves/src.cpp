#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int x[maxn], y[maxn], leaf_speed[maxn];
int board[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int max_time, speed, n;
    std::cin >> max_time >> speed >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> x[i] >> y[i] >> leaf_speed[i];
    
        for(int j = 0; j < max_time; j++){
            if(y[i] * speed == (x[i] + j * speed) * leaf_speed[i]){
                board[j]++;
            }
        }
    }
    
    for(int i = 0; i < max_time; i++){
        std::cout << board[i] << '\n';
    }
}