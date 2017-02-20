/*
ID: vlade.m1
PROG: rectbarn
LANG: C++
 */
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 3005;
int mat[2][maxn];
static bool bomb[maxn][maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("rectbarn.in", "r", stdin);
    freopen("rectbarn.out", "w", stdout);

    int y, x, p;
    cin >> y >> x >> p;

    for(int i = 0; i < p; i++){
    	int py, px;
    	cin >> py >> px;
    	py--, px--;

    	bomb[py][px] = true;
    }
    for(int j = 0; j < maxn; j++){
    	mat[1][j] = 0;
    }
    int nv = 0;
    int ov = 1;

    int max_area = 0;

    for(int i = y - 1; i >= 0; i--){
    	vector<pair<int, int> > v;
    	for(int j = x - 1; j >= 0; j--){
    		mat[nv][j] = mat[ov][j] + 1;
    		if(bomb[i][j]){
    			mat[nv][j] = 0;
    		}
    		while(!v.empty() and mat[nv][j] < v[v.size() - 1].first){
    			if(v.size() >= 2 and v[v.size() - 2].first < mat[nv][j]){
					max_area = max(max_area, (v[v.size() - 1].second - j) * (v[v.size() - 1].first));
    				v[v.size() - 1].first = mat[nv][j];
					max_area = max(max_area, (v[v.size() - 1].second - j + 1) * (v[v.size() - 1].first));
    			} else {
    				max_area = max(max_area, (v[v.size() - 1].second - j) * (v[v.size() - 1].first));
    				v.pop_back();
    			}
    		}

    		if(v.empty() or mat[nv][j] > v[v.size() - 1].first){
    			v.push_back({mat[nv][j], j});
    			max_area = max(max_area, mat[nv][j]);
    		}
    	}
    	while(!v.empty()){
    		max_area = max(max_area, (v[v.size() - 1].second + 1) * (v[v.size() - 1].first));
    		v.pop_back();
    	}

    	nv ^= 1;
    	ov ^= 1;
    }

    cout << max_area << endl;
}

