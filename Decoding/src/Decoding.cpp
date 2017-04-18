#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int l = (n - 1) / 2;
	int r = (n - 1) / 2;
	r++;

	string res = s;
	int mid = (n - 1);
	for(int i = 0; i < n; i++){
		if(mid - l * 2 <= r * 2 - mid){
			res[l] = s[i];
			l--;
		} else {
			res[r] = s[i];
			r++;
		}
	}

	cout << res;
}
