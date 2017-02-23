#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int val[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		sum += val[i];
	}
	sort(val, val + n);

	int capacity;
	cin >> capacity;

	int smallsum = 0;

	int i;
	for(i = 0; i < n; i++){
		if(sum - smallsum - val[i] < capacity){
			break;
		}
		smallsum += val[i];
	}

	cout << i << ' ';

	smallsum = 0;
	for(i = 0; i < n; i++){
		smallsum += val[i];
		if(smallsum >= capacity){
			break;
		}
	}

	cout << n - i - 1;
	return 0;
}
