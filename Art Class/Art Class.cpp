#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double b1;
double b2;
double a4;

int style(int y, int x, int r[500][500], int g[500][500], int b[500][500]){
	double disparance = 0;
	for(int i = y / 10; i + y / 10 < y; i++){
		for(int j = x / 10; j + x / 10 < x; j++){
			int avgr = 0, avgg = 0, avgb = 0;	

			int step = min(4, min(y, x) / 25) + 1;
			int taken = 0;
			for(int k = -step; k <= step; k++){
				for(int l = -step; l <= step; l++){
					if(0 <= i + k and i + k < y){
						if(0 <= j + l and j + l < x){
							avgr += r[i + k][j + l];
							avgg += g[i + k][j + l];
							avgb += b[i + k][j + l];
							taken++;
						}
					}
				}
			}

			double part = ((double) avgr) / ((double) taken) +
						  ((double) avgg) / ((double) taken) +
						  ((double) avgb) / ((double) taken);

			part *= part;
			part *= part;

			disparance += part;
		}
	}

	if(disparance < b1){
 		return 1;
	} else if(disparance < b2){
		return 2;
	} else if(disparance > a4){
		return 4;
	} else {
		return 3;
	}
}

int mat[3][500][500];
int main(){
	int y, x;
	cin >> y >> x;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < 3; k++){
				cin >> mat[k][i][j];
			}
		}
	}

	cout << style(y, x, mat[0], mat[1], mat[2]);
}

