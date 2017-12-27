#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e4;
static bool used[maxn][maxn];
static int gccd[maxn][maxn];

int gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for(int i = 1; i < maxn; i++){
		for(int j = 1; j <= i; j++){
			gccd[i][j] = gccd[j][i] = gcd(i, j);
		}
	}

	for(int x = maxn - 1; x >= 1; x--){
		cout << x << endl;
		queue<int> qa, qb;
		qa.push(x), qb.push(x);

		while(!qa.empty()){
			int a = qa.front(), b = qb.front();
			qa.pop(), qb.pop();

			a = a + b;
			if(a < maxn){
				if(gccd[a][b] != x){
					cout << "NOPE" << endl;
					return 0;
				}
				if(!used[a][b]){
					qa.push(a), qb.push(b);
					used[a][b] = true;
				}
			}
			a -= b;

			b = a + b;
			if(b < maxn){
				if(gccd[a][b] != x){
					cout << "NOPE" << endl;
					return 0;
				}
				if(!used[a][b]){
					qa.push(a), qb.push(b);
					used[a][b] = true;
				}
			}
		}
	}
}

