#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int id[250];
	id['U'] = 1;
	id['D'] = -1;

	id['L'] = 10000;
	id['R'] = -10000;

	int val[n];
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		val[i] = id[c];
	}

	int ways = 0;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += val[j];

			if(sum == 0){
				ways++;
			}
		}
	}

	cout << ways;
	return 0;
}
