#include <bits/stdc++.h>

const static int ay[] = {1, -1, 0, 0};
const static int ax[] = {0, 0, 1, -1};
class Solution {

public:
    int shortestBridge(std::vector<std::vector<int>>& A) {
        int y = A.size();
        int x = A[0].size();
        int dist[y][x];
        memset(dist, -1, sizeof(dist));
        std::queue<int> qpy, qpx;
        std::queue<int> qy, qx;
        
        for(int i = 0; i < y; i++){
        	for(int j = 0; j < x; j++){
        		if(A[i][j] == 1){
        			dist[i][j] = 0;
        			qpy.push(i), qpx.push(j);
        			while(!qpy.empty()){
        				int fry = qpy.front();
        				int frx = qpx.front();
        				qy.push(fry);
        				qx.push(frx);
        				qpy.pop();
        				qpx.pop();

        				for(int k = 0; k < 4; k++){
        					int ni = fry + ay[k];
        					int nj = frx + ax[k];

        					if(0 <= ni and ni < y and 0 <= nj and nj < x and A[ni][nj] == 1 and dist[ni][nj] == -1){
        						dist[ni][nj] = 0;
        						qpy.push(ni);
        						qpx.push(nj);
        					}
        				}
        			}
                    i = y, j = x;
        			break;
        		}
        	}
        }

        while(!qy.empty()){
        	int fry = qy.front();
        	int frx = qx.front();
            qy.pop(), qx.pop();

        	for(int k = 0; k < 4; k++){
				int ni = fry + ay[k];
				int nj = frx + ax[k];

				if(0 <= ni and ni < y and 0 <= nj and nj < x and dist[ni][nj] == -1){
					dist[ni][nj] = dist[fry][frx] + 1;
					qy.push(ni);
					qx.push(nj);
				}        		
        	}
        }

        int res = y + x;
        for(int i = 0; i < y; i++){
        	for(int j = 0; j < x; j++){
        		if(A[i][j] == 1 and dist[i][j] != 0){
        			res = std::min(res, dist[i][j] - 1);
        		}
        	}
        }

        return res;
    }
};