#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int app[2501];
		for(int i = 0; i < 2501; i++){
			app[i] = 0;
		}
		int n;
		cin >> n;
		for(int i = 0; i < n + n - 1; i++){
			for(int j = 0; j < n; j++){
				int ind;
				cin >> ind;
				app[ind]++;
			}
		}


		cout << "Case #" << i + 1 << ": ";
		for(int i = 0; i < 2501; i++){
			if(app[i] % 2 == 1){
				cout << i << ' ';
			}
		}
		cout << endl;
	}
}