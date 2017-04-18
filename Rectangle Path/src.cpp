#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e3 + 1e2;
int val[maxn][maxn];
int dist[maxn][maxn];
int used[maxn][maxn];
const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int y, x;
    cin >> y >> x;
    
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            val[i][j] = 1;
        }
    }
    
    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= x; j++){
            std::cin >> val[i][j];
        }
    }
    
    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= x; j++){
            val[i][j] = val[i][j] + val[i][j - 1] + val[i - 1][j] - val[i - 1][j - 1];
        }
    }
    
    int ry, rx, sy, sx, ey, ex;
    std::cin >> ry >> rx >> sy >> sx >> ey >> ex;
    
    sy = sy + ry - 1, sx = sx + rx - 1;
    ey = ey + ry - 1, ex = ex + rx - 1;
    
    dist[ey][ex] = -1;
    
    queue<int> qy, qx;
    qy.push(sy);
    qx.push(sx);
    dist[sy][sx] = 0;
    used[sy][sx] = true;
    
    while(!qy.empty()){
        int fry = qy.front(), frx = qx.front();
        qy.pop(), qx.pop();    
        
        for(int i = 0; i < 4; i++){
            int ny = fry + ay[i], nx = frx + ax[i];
            
            if(0 <= ny - ry and ny <= y and 0 <= nx - rx and nx <= x){
            } else {
                continue;
            }
            if(!used[ny][nx] and val[ny][nx] - val[ny - ry][nx] - val[ny][nx - rx] + val[ny - ry][nx - rx] == 0){
                qy.push(ny), qx.push(nx);
                used[ny][nx] = true;
                dist[ny][nx] = dist[fry][frx] + 1;
            }
        }
    }
    
    std::cout << dist[ey][ex] << std::endl;
}