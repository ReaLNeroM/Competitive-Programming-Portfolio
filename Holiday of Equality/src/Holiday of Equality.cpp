#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int sum = 0, maxv = 0;
	for(int i = 0; i < n; i++){
		int value;
		cin >> value;
		sum += value;
		maxv = max(maxv, value);
	}

	cout << maxv * n - sum;
}

