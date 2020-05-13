#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 10;

int n;
std::pair<int, int> activities[maxn];
std::pair<std::pair<int, int>, int> ordering[maxn];
int dp[maxn][maxn];
int foll[maxn][maxn];

bool overlap(std::pair<int, int> f, std::pair<int, int> s){
    return (s.first < f.second) and (f.first < s.second);
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n;
        std::cin >> n;

        for(int i = 0; i < n; i++){
            std::cin >> activities[i].first >> activities[i].second;
            ordering[i].first = activities[i];
            ordering[i].second = i;
        }

        std::sort(ordering, ordering + n);

        for(int i = 0; i < n; i++){
            activities[i] = ordering[i].first;
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                int next = std::max(i, j);
                if(next >= n){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int next = std::max(i, j);

                if(
                    (i == 0 or !overlap(activities[i - 1], activities[next])) &&
                    dp[next + 1][j]
                ){
                    dp[i][j] = 1;
                    foll[i][j] = 0;
                } else if(
                    (j == 0 or !overlap(activities[j - 1], activities[next])) &&
                    dp[i][next + 1]
                ){
                    dp[i][j] = 1;
                    foll[i][j] = 1;
                }
            }
        }

        if(!dp[0][0]){
            std::cout << "IMPOSSIBLE";
        } else {
            std::string operations(n, '\0');
            int curri = 0, currj = 0;
            while(std::max(curri, currj) < n){
                int next = std::max(curri, currj);

                switch (foll[curri][currj]){
                    case 0:
                        operations[ordering[next].second] = 'C';
                        curri = next + 1;
                        break;
                    case 1:
                        operations[ordering[next].second] = 'J';
                        currj = next + 1;
                        break;
                }
            }

            std::cout << operations;
        }

        std::cout << '\n';
    }
}