#include <iostream>

using namespace std;
typedef long long ll;

int rot[24][6] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 1, 4, 3, 2, 6, 5 },
		{ 1, 5, 3, 6, 4, 2 },
		{ 1, 6, 3, 5, 2, 4 },

		{ 2, 1, 4, 3, 6, 5 },
		{ 2, 3, 4, 1, 5, 6 },
		{ 2, 5, 4, 6, 1, 3 },
		{ 2, 6, 4, 5, 3, 1 },

		{ 3, 2, 1, 4, 6, 5 },
		{ 3, 4, 1, 2, 5, 6 },
		{ 3, 5, 1, 6, 2, 4 },
		{ 3, 6, 1, 5, 4, 2 },

		{ 4, 1, 2, 3, 5, 6 },
		{ 4, 3, 2, 1, 6, 5 },
		{ 4, 5, 2, 6, 3, 1 },
		{ 4, 6, 2, 5, 1, 3 },

		{ 5, 1, 6, 3, 2, 4 },
		{ 5, 3, 6, 1, 4, 2 },
		{ 5, 4, 6, 2, 1, 3 },
		{ 5, 2, 6, 4, 3, 1 },

		{ 6, 1, 5, 3, 4, 2 },
		{ 6, 3, 5, 1, 2, 4 },
		{ 6, 2, 5, 4, 1, 3 },
		{ 6, 4, 5, 2, 3, 1 }
};

const int colored = 117649; // 7^6
static bool used[colored];

int main() {
	ios::sync_with_stdio(false);

	int boxes;
	cin >> boxes;

	int b[boxes][6];
	for(int i = 0; i < boxes; i++){
		for(int j = 0; j < 6; j++){
			cin >> b[i][j];
		}
	}

	int res = boxes * 6;
	for(int i = 0; i < colored; i++){
		if(!used[i]){
			int c[6];
			for(int ite = 0, copy = i; ite < 6; ite++, copy /= 7){
				c[ite] = copy % 7;
			}

			int minn[boxes];
			for(int j = 0; j < boxes; j++){
				minn[j] = 6;
			}

			for(int j = 0; j < 24; j++){
				int val = 0;
				for(int k = 5; k >= 0; k--){
					val *= 7;
					val += c[rot[j][k] - 1];
				}
				used[val] = true;

				int sc[6];
				for(int ite = 0, copy = val; ite < 6; ite++, copy /= 7){
					sc[ite] = copy % 7;
				}

				for(int k = 0; k < boxes; k++){
					int diff = 0;
					for(int l = 0; l < 6; l++){
						if(sc[l] != b[k][l]){
							diff++;
						}
					}

					minn[k] = min(minn[k], diff);
				}
			}

			int change = 0;
			for(int j = 0; j < boxes; j++){
				change += minn[j];
			}

			res = min(res, change);
		}
	}

	cout << res;
	return 0;
}
