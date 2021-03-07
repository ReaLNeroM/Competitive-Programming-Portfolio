// https://nena20.kattis.com/problems/march6.longestcommonsubsequence

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int mat[26][26];
std::string s;
int dp[27];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n, alpha;
    std::cin >> n >> alpha;

    memset(mat, 1, sizeof(mat));

    for(int i = 0; i < n; i++){
        cin >> s;

        for(int j = 0; j < alpha; j++){
            for(int k = 0; k < j; k++){
                mat[s[j] - 'A'][s[k] - 'A'] = false;
            }
        }
    }

    int res = 0;

    dp[0] = 0;
    for(int i = 1; i <= alpha; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(mat[s[j - 1] - 'A'][s[i - 1] - 'A']){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    std::cout << res << '\n';
}
