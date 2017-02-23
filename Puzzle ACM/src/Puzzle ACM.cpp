#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for(int test = 0; test < cases; test++){
		int y, x;
		cin >> y >> x;
		char m[y][x];

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				cin >> m[i][j];
			}
		}

		bool pos = true;

		//!!!

		if(pos){
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
	return 0;
}
