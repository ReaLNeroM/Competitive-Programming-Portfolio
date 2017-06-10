#include <bits/stdc++.h>
 
const int maxn = 2005;
int dp[maxn][maxn];
int pari[maxn][maxn];
int parj[maxn][maxn];
int n;
char s[maxn];
 
int dfs(int i, int j){
    if(dp[i][j] == -1){
        dp[i][j] = 0;
 
        if(i == n and j == 0){
            dp[i][j] = 1;
            pari[i][j] = i;
            parj[i][j] = j;
        }
        if(i != n){
            if(dfs(i + 1, j + 1)){
                dp[i][j] = 1;
                pari[i][j] = i + 1;
                parj[i][j] = j + 1;
            } else if(j != 0 and dfs(i + 1, j - 1)){
                dp[i][j] = 2;
                pari[i][j] = i + 1;
                parj[i][j] = j - 1;
            }
        }
    }
}
 
void dfs2(int i, int j){
    if(i == n){
        return;
    }
    if(dp[i][j] == 1){
        std::cout << '(';
        dfs2(pari[i][j], parj[i][j]);
    } else {
        std::cout << ')';
        dfs2(pari[i][j], parj[i][j]);
    }
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::string ss = "";
    std::cin >> ss;
    n = ss.size();
 
    for(int i = 0; i < n; i++){
        s[i] = ss[i];
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
 
    dfs(0, 0);
 
    if(!dfs(0, 0)){
        std::cout << -1 << std::endl;
        return 0;
    }
 
    dfs2(0, 0);
}