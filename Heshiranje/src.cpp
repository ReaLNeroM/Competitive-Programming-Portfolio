#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxmod = (1 << 22);
ll n, k, m, mod;
ll res = 0;
 
int board[2][maxmod];
 
void dfs(ll pos, ll currmod){
    if(pos == n - 1){
        int goal = (currmod * 33) % mod;
        goal ^= k;
 
        if(1 <= goal and goal <= 26){
            res++;
        }
 
        return;
    }
 
    for(ll i = 1; i <= 26; i++){
        dfs(pos + 1, ((currmod * 33) ^ i) % mod);
    }
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> n >> k >> m;
 
    mod = (1 << m);
 
    if(n <= 6){
        dfs(0, 0);
 
        std::cout << res << '\n';
    } else {
        if(mod > maxmod){
            return -1;
        }
        int curr = 0, next = 1;
 
        board[curr][0] = 1;
 
        for(int i = 1; i <= n - 1; i++){
            if(i != 1){
                memset(board[next], 0, sizeof(board[next]));
            }
 
            for(int j = 0; j < mod; j++){
                for(int k = 1; k <= 26; k++){
                    board[next][(j * 33 ^ k) % mod] += board[curr][j];
                }
            }
 
            curr ^= 1, next ^= 1;
        }
 
        for(int j = 0; j < mod; j++){
            int goal = (j * 33) % mod;
            goal ^= k;
 
            if(1 <= goal and goal <= 26){
                res += board[curr][j];
            }
        }
 
        std::cout << res << '\n';
    }
}