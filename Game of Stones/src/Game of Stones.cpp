#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int winner[60][2];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int piles_1 = 0;
	int piles_o = 0;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		if(val[i] <= 2){
			piles_1++;
		} else {
			piles_o++;
		}
	}

	int res = 0;

	if(piles_1 % 2 == 1){
		res = !res;
	}

	if(piles_o % 2 == 0){
		res = !res;
	}


	if(res){
		cout << "YES";
	} else {
		cout << "NO";
	}
}

