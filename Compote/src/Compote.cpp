#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int res = min(a / 1, min(b / 2, c / 4));

	cout << res * 7 << endl;
}
