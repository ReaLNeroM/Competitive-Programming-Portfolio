#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int n;
map<int, int> s, b;
map<int, int> ds, db;
map<int, int> m;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++){
		int index, operation;
		cin >> index >> operation;
		index--;

		if(operation == 0){
			ds[-index] = -1;
			db[index] = -1;
		} else {
			int value;
			cin >> value;
			s[-index] = value;
			b[index] = value;
		}

		if(m.empty()){
			cout << -1 << '\n';
		} else {
			cout << (m.rbegin())->second << '\n';
		}
	}
}

