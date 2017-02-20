/*
ID: vlade.m1
PROG: rect1
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxy = 1e4 + 5;
const int maxn = 1e3;
const int max_col = 2505;
int py1[maxn], py2[maxn], px1[maxn], px2[maxn];
int col[maxn];
int area[max_col];
bool dis[maxy];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);

	int y, x, p;
	cin >> x >> y >> p;

	for(int i = 0; i < p; i++){
		cin >> px1[i] >> py1[i] >> px2[i] >> py2[i];
		cin >> col[i];
		py2[i]--, px2[i]--;
		dis[py1[i]] = true, dis[py2[i] + 1] = true;
	}
	dis[y] = true;

	for(int i = 0; i < y; i++){
		int sweep = 0;
		for(int j = i; j < y; j++){
			if(dis[j + 1]){
				sweep = j - i + 1;
				break;
			}
		}
		int next[x];
		bool exists[x];
		for(int j = 0; j < x; j++){
			next[j] = j + 1;
			exists[j] = 1;
		}
		next[x - 1] = -1;

		for(int j = p - 1; j >= 0; j--){
			if(py1[j] <= i and i <= py2[j]){
				int curr = px1[j];
				while(curr <= px2[j] and curr != -1){
					if(exists[curr]){
						area[col[j]] += sweep;
						exists[curr] = false;
					}

					while(next[curr] != -1 and exists[next[curr]] == false){
						next[curr] = next[next[curr]];
					}

					curr = next[curr];
				}
			}
		}

		i += sweep - 1;
	}

	int left = y * x;
	for(int i = 0; i < max_col; i++){
		left -= area[i];
	}
	area[1] += left;

	for(int i = 0; i < max_col; i++){
		if(area[i] != 0){
			cout << i << ' ' << area[i] << endl;
		}
	}
}

