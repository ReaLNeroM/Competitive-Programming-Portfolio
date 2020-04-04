#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll INF = 1000000000000000010;

int m[maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n;
        std::cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                std::cin >> m[i][j];
            }
        }

        int trace = 0;
        int reprows = 0, repcols = 0;

        for(int i = 0; i < n; i++){
            bool repeating = false;

            std::set<int> seen;
            for(int j = 0; j < n; j++){
                if(seen.find(m[i][j]) != seen.end()){
                    repeating = true;
                }
                seen.insert(m[i][j]);
            }

            if(repeating){
                reprows++;
            }
        }

        for(int j = 0; j < n; j++){
            bool repeating = false;

            std::set<int> seen;
            for(int i = 0; i < n; i++){
                if(seen.find(m[i][j]) != seen.end()){
                    repeating = true;
                }
                seen.insert(m[i][j]);
            }

            if(repeating){
                repcols++;
            }
        }

        for(int i = 0; i < n; i++){
            trace += m[i][i];
        }

        std::cout << trace << ' ' << reprows << ' ' << repcols;

        std::cout << '\n';
    }
}