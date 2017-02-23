#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	double l;
	cin >> n >> l;

	double val[n];
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + n);

	double covered = -500;
	int used = 0;
	for(int i = 0; i < n; i++){
		if(covered + 0.00001 < val[i]){
			used++;
			covered = val[i] + l + l;
		}
	}

	cout << used;
	return 0;
}
