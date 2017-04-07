#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		string v[2][4];
		
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 4; j++){
				cin >> v[i][j];
			}

			sort(v[i], v[i] + 4);
		}

		int found = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(v[0][i] == v[1][j]){
					found++;
				}
			}
		}

		if(found >= 2){
			cout << "similar\n";
		} else {
			cout << "dissimilar\n";
		}
	}
}