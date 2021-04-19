// https://codeforces.com/gym/103049/problem/I

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 800 + 1e2;
int val[maxn];
int visit[3][maxn];
bool intersect[3][3][maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> val[i];
        val[n + i] = val[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> visit[i][j];
            visit[i][n + j] = visit[i][j];
        }
    }

    int res = 0;

    for(int a = 0; a < 3; a++){
        for(int b = a + 1; b < 3; b++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j){
                        continue;
                    }

                    int currI = i + 1;
                    int currITime = 0;
                    int currJ = j + 1;
                    int currJTime = 0;

                    while(currI != -(n + i) and currJ != -(n + j)){
                        int currIStep;
                        if(currI < 0){
                            currIStep = currITime + val[-currI - 1];
                        } else {
                            currIStep = currITime + visit[a][currI - 1];
                        }

                        int currJStep = currJTime + val[currJ];
                        if(currJ < 0){
                            currJStep = currJTime + val[-currJ - 1];
                        } else {
                            currJStep = currJTime + visit[b][currJ - 1];
                        }

                        if(currIStep == currJStep){
                            if(currI < 0){
                                currI = -currI + 1;
                            } else {
                                currI = -currI;
                            }
                            currITime = currIStep;
                            if(currJ < 0){
                                currJ = -currJ + 1;
                            } else {
                                currJ = -currJ;
                            }
                            currJTime = currJStep;
                        } else if(currIStep < currJStep){
                            if(currI < 0){
                                currI = -currI + 1;
                            } else {
                                currI = -currI;
                            }
                            currITime = currIStep;
                        } else {
                            if(currJ < 0){
                                currJ = -currJ + 1;
                            } else {
                                currJ = -currJ;
                            }
                            currJTime = currJStep;
                        }

                        if(currI > 0 and currJ > 0 and (currI - 1) % n == (currJ - 1) % n){
                            intersect[a][b][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(!intersect[0][1][i][j]){
                for(int k = 0; k < n; k++){
                    if(i == k or j == k){
                        continue;
                    }
                    if(!intersect[0][2][i][k] and !intersect[1][2][j][k]){
                        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    cout << "impossible\n";
}
