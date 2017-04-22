#include <bits/stdc++.h>
  
typedef long long ll;
  
const int maxn = 2002;
const int maxinc = 101;
int start[maxn];
int end[maxn];
int pref = 100;
int n;
static int dist[2][maxinc][maxinc];
  
int main(){
    std::ios::sync_with_stdio(false);
  
    std::cin >> n;
  
    for(int i = 0; i < n; i++){
        std::cin >> start[i];
    }
  
    for(int i = 0; i < n; i++){
        std::cin >> end[i];
    }
  
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < maxinc; j++){
            for(int k = 0; k < maxinc; k++){
                dist[i][j][k] = 1e9;
            }
        }
    }
  
    int res = 1e9;
    dist[0][0][0] = 0;
    int old = 0, nnew = 1;
    for(int i = 0; i < n; i++){
        for(int why_not = 0; why_not < 2; why_not++){
            for(int j = 0; j < maxinc; j++){
                for(int k = 0; k < maxinc; k++){
                    if(j != 0){
                        dist[old][j][k] = std::min(dist[old][j][k], dist[old][j - 1][k] + 1);
                    }
                    if(k != 0){
                        dist[old][j][k] = std::min(dist[old][j][k], dist[old][j][k - 1] + 1);
                    }
                }
            }
            for(int j = maxinc - 1; j >= 0; j--){
                for(int k = maxinc - 1; k >= 0; k--){
                    if(j != maxinc - 1){
                        dist[old][j][k] = std::min(dist[old][j][k], dist[old][j + 1][k]);
                    }
                    if(k != maxinc - 1){
                        dist[old][j][k] = std::min(dist[old][j][k], dist[old][j][k + 1]);
                    }
                }
            }
        }
        for(int j = 0; j < maxinc; j++){
            for(int k = 0; k < maxinc; k++){
                dist[nnew][j][k] = 1e9;
            }   
        }
        for(int j = 0; j < maxinc; j++){
            for(int k = 0; k < maxinc; k++){
                if(start[i] + j - k == end[i]){
                    dist[nnew][j][k] = dist[old][j][k];
                }
            }
        }
  
        old ^= 1, nnew ^= 1;
    }
  
    for(int i = 0; i < maxinc; i++){
        for(int j = 0; j < maxinc; j++){
            res = std::min(res, dist[old][i][j]);
        }
    }
  
    std::cout << res << std::endl;
}