#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int depend[maxn][2];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		char c;
		cin >> c;

		if(c == '?'){
			val[i] = -1;
		} else if(c == '0'){
			val[i] = 0;
		} else if(c == '1'){
			val[i] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		string ca = a, cb = b;
		a.erase(a.begin()), b.erase(b.begin());
		stringstream istr;

		istr << a << ' ' << b;
		istr >> depend[i][0];
		istr >> depend[i][1];

		if(ca[0] == 'x'){
			depend[i][0] += 10000;
		}
		if(cb[0] == 'x'){
			depend[i][1] += 10000;
		}

		depend[i][0]--, depend[i][1]--;
	}

}

