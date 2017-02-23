#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int val[2 * n];
	int i = 0;

	int maxn[2] = {n - (n % 2), n - !(n % 2)};
	int startn[2] = {2, 1};
	if(n % 2 == 1){
		swap(maxn[0], maxn[1]);
		swap(startn[0], startn[1]);
	}

	int pos = startn[0];

	while(pos <= maxn[0]){
		val[i] = pos;
		pos += 2;
		i++;
	}

	pos = maxn[0];
	while(pos >= startn[0]){
		val[i] = pos;
		pos -= 2;
		i++;
	}

	pos = startn[1];

	while(pos <= maxn[1]){
		val[i] = pos;
		pos += 2;
		i++;
	}

	pos -= 4;
	while(pos >= startn[1]){
		val[i] = pos;
		pos -= 2;
		i++;
	}

	val[2 * n - 1] = n;

	for(int i = 0; i < 2 * n; i++){
		cout << val[i] << ' ';
	}
	return 0;
}
