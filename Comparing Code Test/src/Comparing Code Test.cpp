#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n = 1000;

	int highest = 0;
	for(int biggest = 0; biggest <= n; biggest++){
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(n - i < biggest or n - j < biggest){
				} else {
					res += biggest;
				}
			}
		}

		highest = max(highest, res);
	}

	cout << highest;
}

