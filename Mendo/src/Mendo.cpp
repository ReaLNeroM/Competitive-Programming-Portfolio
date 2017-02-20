#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int dist(int a[], int b[]){
	return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int p[3][2];
	p[0][0] = 5;
	p[0][1] = 6;

	for(p[1][0] = 0; p[1][0] <= 6; p[1][0]++){
		for(p[1][1] = 0; p[1][1] <= 6; p[1][1]++){
			for(p[2][0] = 0; p[2][0] <= 6; p[2][0]++){
				for(p[2][1] = 0; p[2][1] <= 6; p[2][1]++){
					if(dist(p[0], p[1]) == 41){
						if(dist(p[0], p[2]) == 41 or dist(p[1], p[2]) == 41){
							cout << p[0][0] << ' ' << p[0][1] << ' ' << p[1][0] << ' ' << p[1][1] << ' ' << p[2][0] << ' ' << p[2][1] << endl;
						}
					} else {
						if(dist(p[0], p[2]) == 41 and dist(p[1], p[2]) == 41){
							cout << p[0][0] << ' ' << p[0][1] << ' ' << p[1][0] << ' ' << p[1][1] << ' ' << p[2][0] << ' ' << p[2][1] << endl;
						}
					}
				}
			}
		}
	}
}
