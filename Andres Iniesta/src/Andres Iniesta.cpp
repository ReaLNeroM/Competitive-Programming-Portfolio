#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int y, x, b;
	cin >> y >> x >> b;

	char mat[y][x];
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cin >> mat[i][j];
		}
	}

	int top[b + 1], bottom[b + 1], left[b + 1], right[b + 1];
	int countv[b + 1], counth[b + 1];

	int res = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			int toppos = i - 1;
			int bottompos = i + 1;
			int leftpos = j - 1;
			int rightpos = j + 1;

			for(int k = 0; k <= b; k++){
				while(toppos >= 0 and mat[toppos][j] == '.'){
					toppos--;
				}
				while(bottompos < y and mat[bottompos][j] == '.'){
					bottompos++;
				}
				while(leftpos >= 0 and mat[i][leftpos] == '.'){
					leftpos--;
				}
				while(rightpos < x and mat[i][rightpos] == '.'){
					rightpos++;
				}

				top[k] = i - max(-1, toppos) - 1;
				bottom[k] = min(y, bottompos) - i - 1;
				left[k] = j - max(-1, leftpos) - 1;
				right[k] = min(x, rightpos) - j - 1;

				toppos--;
				bottompos++;
				leftpos--;
				rightpos++;
			}
			for(int k = 0; k <= b; k++){
				countv[k] = 0;
				counth[k] = 0;
				for(int l = 0; l <= k; l++){
					countv[k] = max(countv[k], top[l] + bottom[k - l]);
					counth[k] = max(counth[k], left[l] + right[k - l]);
				}
			}

			for(int l = 0; l <= b and b - l - (mat[i][j] == '*') >= 0; l++){
				res = max(res, countv[l] + counth[b - l - (mat[i][j] == '*')] + 1);
			}
		}
	}

	cout << res;
	return 0;
}
