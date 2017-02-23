#include <iostream>

typedef long long ll;

std::string str1, str2;
int dp[1001][1001];
int ways[1001][1001];
const int mod = 750083;

int find(int i, int j){
    if(dp[i][j] == str1.length() + str2.length()){
        if(i == str1.length()){
            dp[i][j] = str2.length() - j;
            ways[i][j] = 1;
        } else if(j == str2.length()){
            dp[i][j] = str1.length() - i;
            ways[i][j] = 1;
        } else {
            if(str1[i] == str2[j]){
                dp[i][j] = find(i + 1, j + 1) + 1;
                ways[i][j] = ways[i + 1][j + 1];
            } else {
                if(find(i + 1, j) + 1 < dp[i][j]){
                    dp[i][j] = find(i + 1, j) + 1;
                    ways[i][j] = ways[i + 1][j];
                } else if(find(i + 1, j) + 1 == dp[i][j]){
                    ways[i][j] += ways[i + 1][j];
                }
                if(find(i, j + 1) + 1 < dp[i][j]){
                    dp[i][j] = find(i, j + 1) + 1;
                    ways[i][j] = ways[i][j + 1];
                } else if(find(i, j + 1) + 1 == dp[i][j]){
                    ways[i][j] += ways[i][j + 1];
                }
            }
        }

        ways[i][j] %= mod;
    }

    return dp[i][j];
}
int main() {
    std::cin >> str1 >> str2;

    for(int i = 0; i <= str1.length(); i++){
        for(int j = 0; j <= str2.length(); j++){
            dp[i][j] = str1.length() + str2.length();
            ways[i][j] = 0;
        }
    }

    find(0, 0);

    std::cout << ways[0][0];
    return 0;
}
