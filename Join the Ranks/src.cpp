#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 14;
const ll INF = 1000000000000000010;

int val[maxn];
int cp[maxn];
int expected[maxn][maxn];
std::vector<std::vector<int>> precalc[maxn][maxn];
int r, s;

void perform(int a, int b){
    int i = r * s - a - b;
    for(int k = 0; k < a; k++){
        cp[k] = val[i + k];
    }

    for(int k = 0; k < b; k++){
        val[i + k] = val[i + a + k];
    }
    for(int k = 0; k < a; k++){
        val[i + b + k] = cp[k];
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    expected[     2][ 2] = 1;
    expected[     2][ 3] = 2;
    expected[     2][ 4] = 3;
    expected[     2][ 5] = 4;
    expected[     2][ 6] = 5;
    expected[     2][ 7] = 6;
    expected[     3][ 2] = 2;
    expected[ 3][ 3] = 3;
    expected[ 3][ 4] = 5;
    expected[ 4][ 2] = 2;
    expected[ 4][ 3] = 4;
    expected[ 5][ 2] = 3;
    precalc[5][2] = {{4, 5},    {3, 2},    {5, 2}};
    precalc[3][3] = {{2, 5},    {2, 3},    {5, 3}};
    precalc[4][3] = {{3, 6},    {4, 7},    {5, 3},    {7, 3}};
    precalc[3][4] = {{2, 9},    {2, 7},    {2, 5},    {7, 3},    {2, 3}};
    precalc[4][2] = {{3, 2},    {5, 2}};

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        std::cin >> r >> s;

        for(int i = 0; i < r * s; i++){
            val[i] = i % r;
        }

        if(expected[r][s] != (s - 1) * (r - 1)){
            std::cout << expected[r][s] << '\n';
            for(auto& i : precalc[r][s]){
                std::cout << i[1] << ' ' << i[0] << '\n';
                perform(i[0], i[1]);
            }
        } else {
            std::cout << (s - 1) * (r - 1) << '\n';
            int currs = s;

            for(int i = r - 1; i >= 1; i--){
                for(int j = 1; j <= s - 1; j++){
                    std::cout << (i+1)*j << ' ' << i << '\n';
                    perform(i, (i+1)*j);
                }
                currs -= 1;
            }
        }
    }
}
