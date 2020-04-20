#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 15;
const ll INF = 1000000000000000010;

int val[maxn];
int cp[maxn][maxn];
int expected[maxn][maxn];
std::vector<std::vector<int>> precalc[maxn][maxn];

int ans[maxn][2];
int n, r, s;
int best;
bool reported = false;

void dfs(int step, int ls, int rs){
    while(ls < rs and val[ls] == ls / s){
        ls++;
    }

    if(ls == rs){
        best = std::min(best, step);
        if(step == expected[r][s] and !reported){
            // std::cout << r << ' ' << s << ' ';
            // for(int i = 0; i < step; i++){
            //     std::cout << ans[i][0] << ' ' << ans[i][1] << '\t';
            // }
            // std::cout << std::endl;
            reported = true;
        }
        return;
    }

    if(step + 1 >= best){
        return;
    }

    for(int i = ls; i < n; i++){
        for(int j = i; j < n; j++){
            int a = j - i + 1;
            int b = (rs - i) - a;
            ans[step][0] = a;
            ans[step][1] = b;

            for(int k = 0; k < a; k++){
                cp[step][k] = val[i + k];
            }

            for(int k = 0; k < b; k++){
                val[i + k] = val[i + a + k];
            }
            for(int k = 0; k < a; k++){
                val[i + b + k] = cp[step][k];
            }

            dfs(step + 1, ls, rs);

            for(int k = b - 1; k >= 0; k--){
                val[i + a + k] = val[i + k];
            }
            for(int k = 0; k < a; k++){
                val[i + k] = cp[step][k];
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    expected[3][3] = 3;
    expected[3][4] = 5;
    expected[4][2] = 2;
    expected[4][3] = 4;
    expected[5][2] = 3;
    int curr_num = 1;

    for(r = 2; r <= 5; r++){
        for(s = 2; s <= 7; s++){
            if(r * s <= 14){
                if(s == 7 and r == 2){
                    continue;
                }
                n = r * s;
                reported = false;
                for(int i = 0; i < n; i++){
                    val[i] = i % r;
                }

                best = (s - 1) * (r - 1);
                dfs(0, 0, n);

                if(best != (s - 1) * (r - 1)){
                    std::cout << curr_num << ' ' << r << ' ' << s << ' ' << best << std::endl;
                } else {
                    std::cout << curr_num << "     " << r << ' ' << s << ' ' << best << std::endl;
                }
                curr_num += 1;
            }
        }
    }
}
