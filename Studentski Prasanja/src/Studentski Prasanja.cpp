#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int indiv[n];
	int together[n - 1];

	for(int i = 0; i < n; i++){
		cin >> indiv[i];
	}
	for(int i = 0; i < n - 1; i++){
		cin >> together[i];
	}


	int best[n + 1];
	int nextpair[n + 1];
	best[n] = 0;
	nextpair[n] = -1;
	best[n - 1] = indiv[n - 1];
	nextpair[n - 1] = -1;
	for(int i = n - 2; i >= 0; i--){
		if(indiv[i] + best[i + 1] <= together[i] + best[i + 2]){
			best[i] = indiv[i] + best[i + 1];
			nextpair[i] = nextpair[i + 1];
		} else {
			best[i] = together[i] + best[i + 2];
			nextpair[i] = i;
		}
	}

	int pos = nextpair[0];
	while(pos >= 0 and pos < n){
		cout << pos + 1 << ' ' << pos + 2 << endl;
		pos = nextpair[pos + 2];
	}
	return 0;
}
