#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

union x {
	int ii;
	char x[4];
};

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	x v;
	v.ii = 305419896;

	for(int i = 0; i < 4; i++){
		cout << (int) v.x[i] << endl;
	}
}
