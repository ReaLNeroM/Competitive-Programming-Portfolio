#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 10;
int y, x;
std::string s;
int hops;
int hop[maxn];
int mat[maxn][maxn];
int dp[maxn][maxn][maxn];

int dfs(int a, int b, int c){
    if(dp[a][b][c] != -1){
        return dp[a][b][c];
    }

    int& ans = dp[a][b][c];
    ans = 1000000000;
    if(a == y - 1 and b == 0){
        ans = mat[a][b];
        return ans;
    }
    if(a != y - 1){
        ans = std::min(ans, dfs(a + 1, b, c) + mat[a][b]);
    }
    if(b != 0){
        ans = std::min(ans, dfs(a, b - 1, c) + mat[a][b]);
    }
    if(c != 0){
        int hopp = hop[c - 1] + 1;
        if(a + hopp < y){
            ans = std::min(ans, dfs(a + hopp, b, c - 1) + mat[a][b]);
        }
        if(b - hopp >= 0){
            ans = std::min(ans, dfs(a, b - hopp, c - 1) + mat[a][b]);
        }
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> x >> y;

    std::cin >> s;
    hops = s.size();

    for(int i = 0; i < hops; i++){
        hop[i] = s[i] - '0';
    }

    for(int i = 0; i < y; i++){
        std::cin >> s;
        for(int j = 0; j < x; j++){
            mat[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            for(int k = 0; k < maxn; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    int res = 1000000000;
    for(int k = hops; k >= 0; k--){
        res = std::min(res, dfs(0, x - 1, k));
    }
    std::cout << res << '\n';
}
