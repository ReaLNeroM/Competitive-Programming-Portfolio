#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 1e2;
const double eps = 0.0000000000001;
int val[maxn];
int used[maxn];

int gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int res = 0;
    for(int y = 1; y <= n; y++){
		for(int a = y; a <= n and a <= n + y - a; a += y){
			int b = n + y - a;
			if(b >= 1 and gcd(a, b) == y and a + b - y == n){
				res++;
			}
		}
    }

    cout << res;
}
