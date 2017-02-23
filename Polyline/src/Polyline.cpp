#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int c[3][2];
	for(int i = 0; i < 3; i++){
		cin >> c[i][0] >> c[i][1];
	}

	if((c[0][0] == c[1][0] and c[1][0] == c[2][0]) or (c[0][1] == c[1][1] and c[1][1] == c[2][1])){
		cout << 1;
	} else {
		bool possible = false;

		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(j != i){
					for(int k = 0; k < 3; k++){
						if(k != i and k != j){
							int minx = min(c[i][1], c[j][1]), maxx = max(c[i][1], c[j][1]);
							if((c[i][0] == c[k][0] or c[j][0] == c[k][0]) and minx <= c[k][1] and c[k][1] <= maxx){
								possible = true;
							}
							int miny = min(c[i][0], c[j][0]), maxy = max(c[i][0], c[j][0]);
							if((c[i][1] == c[k][1] or c[j][1] == c[k][1]) and miny <= c[k][0] and c[k][0] <= maxy){
								possible = true;
							}
						}
					}
				}
			}
		}

		cout << ((possible) ? 2 : 3);
	}
	return 0;
}
