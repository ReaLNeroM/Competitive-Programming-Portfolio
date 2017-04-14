#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mat[21][21];
const int addery[] = {1, -1, 0, 0};
const int adderx[] = {0, 0, 1, -1};
int y, x;

ll dfs(int i, int j, int bit){
    if(bit == 2097151){
        return 1;
    }
    ll sum = 0;
    for(int k = 0; k < 4; k++){
        int ni = i + addery[k];
        int nj = j + adderx[k];

        if(ni >= 0 and ni < y and nj >= 0 and nj < x and mat[ni][nj] != -1 and ((1 << mat[ni][nj]) & bit) == 0){
            sum += dfs(ni, nj, bit | (1 << mat[ni][nj]));
        }
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> y >> x;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            string str;
            cin >> str;
            if(str[0] != 'P'){
                mat[i][j] = -1;
            } else {
                mat[i][j] = (str[1] - '0') * 10 + str[2] - '0' - 1;
            }
        }
    }

    auto first_time = std::chrono::high_resolution_clock::now();
    ll res = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(mat[i][j] != -1){
                res += dfs(i, j, 1 << mat[i][j]);
            }
        }
    }
    auto second_time = std::chrono::high_resolution_clock::now() - first_time;

    cout << std::chrono::duration_cast<std::chrono::milliseconds>(second_time).count() << endl;


    cout << res;
    return 0;
}
