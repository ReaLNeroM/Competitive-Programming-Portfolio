#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;

	ll val[n], mins[n], minp[n];

	minp[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		if(i != 0){
			minp[i] = minp[i - 1];
			if(val[i] < val[minp[i]]){
				minp[i] = i;
			}
		}
	}

	mins[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		mins[i] = mins[i + 1];
		if(val[i] <= val[mins[i]]){
			mins[i] = i;
		}
	}

	ll res = 0, maxx = 0;
	for(int i = 0; i < n; i++){
		res = 0;
		if(val[mins[i]] <= val[minp[i]]){
			res += mins[i] - i;
			res += n * val[mins[i]];
		} else {
			res += n - (i - minp[i]);
			res += n * val[minp[i]];
		}
		maxx = max(maxx, res);
	}

	cout << maxx;
	return 0;
}
