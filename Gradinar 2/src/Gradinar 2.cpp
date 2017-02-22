#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3;
char mat[maxn][maxn];
int sum[maxn][maxn];
int dist[maxn][maxn];

vector<pair<int, int>> c;
vector<int> comp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int y, xx;
    cin >> y >> xx;

    int w;
    cin >> w;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < xx; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'C'){
                c.push_back({i, j});
            }
        }
    }

    const int ay[] = {1, -1, 0, 0};
    const int ax[] = {0, 0, 1, -1};

    for(int x = 0; x < c.size(); x++){
    	for(int i = 0; i < y; i++){
    		for(int j = 0; j < xx; j++){
    			dist[i][j] = 1e9;
    		}
    	}

    	queue<pair<int, int>> q;
    	q.push(c[x]);
    	dist[c[x].first][c[x].second] = 0;

    	while(!q.empty()){
    		int fry = q.front().first;
    		int frx = q.front().second;
    		int frdist = dist[fry][frx];
    		q.pop();
    		if(frdist > w){
    			break;
    		}
    		sum[fry][frx]++;

    		for(int i = 0; i < 4; i++){
    			int ni = fry + ay[i];
    			int nj = frx + ax[i];

    			if(0 <= ni and ni < y and 0 <= nj and nj < xx and mat[fry][frx] != '#' and dist[ni][nj] == 1e9){
    				dist[ni][nj] = dist[fry][frx] + 1;
    				q.push({ni, nj});
    			}
    		}
    	}
    }

    int best = -1;
    int besty = 0, bestx = 0;
    for(int i = 0; i < y; i++){
    	for(int j = 0; j < xx; j++){
    		if(mat[i][j] != 'C' and mat[i][j] != '#'){
				int found = sum[i][j];

				if(found > best){
					best = found;
					besty = i;
					bestx = j;
				}
    		}
    	}
    }

    cout << besty + 1 << ' ' << bestx + 1 << endl;
}
