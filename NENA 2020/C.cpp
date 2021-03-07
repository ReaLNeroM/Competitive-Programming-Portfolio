// https://nena20.kattis.com/problems/march6.exammanipulation

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e4 + 1e2;
bool ans[maxn][15];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;

    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0; j < k; j++){
            ans[i][j] = (s[j] == 'T');
        }
    }

    int res = 0;

    for(int bitset = 0; bitset < (1 << k); bitset++){
        int lowestscore = k;
        bool rec[k];
        for(int i = 0, bit = 1; i < k; i++, bit *= 2){
            rec[i] = ((bit & bitset) != 0);
        }

        for(int i = 0; i < n; i++){
            int myscore = 0;
            for(int j = 0; j < k; j++){
                if(ans[i][j] == rec[j]){
                    myscore++;
                }
            }
            lowestscore = min(lowestscore, myscore);
        }
        res = max(res, lowestscore);
    }

    std::cout << res << '\n';
}
