#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
map<int, int> m;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int ind;
		cin >> ind;

		m[ind]++;
	}

	if(m.size() == 1){
		cout << 0 << endl;
		return 0;
	}
	cout << n - m.begin()->second - m.rbegin()->second;
}

