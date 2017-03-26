#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + n);
	for(int i = 0; i < n; i++){
		cout << val[i] << ' ';
	}
}