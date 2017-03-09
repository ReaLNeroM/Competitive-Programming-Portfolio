#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		int bff[n];
		for(int i = 0; i < n; i++){
			cin >> bff[i];
			bff[i]--;
		}

		int res = 0;

		for(int i = 0; i < n; i++){
			int used[n];
			int place[n];
			for(int j = 0; j < n; j++){
				used[j] = -1;
				place[j] = -1;
			}
			int pos = i;
			cout << pos << ' ';
			int found = 0;
			int prev = -1;
			while(used[pos] == -1){
				used[pos] = found;
				place[found] = pos;
				found++;
				prev = pos;
				pos = bff[pos];
				cout << pos << ' ';
			}
			cout << endl;

			if(place[(found - 1 + found - 1) % found] == pos or place[0] == pos){
				res = max(res, found);
			}
		}

		cout << "Case #" << i + 1 << ": ";
		cout << res;
		cout << endl;
	}
}