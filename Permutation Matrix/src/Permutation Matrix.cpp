#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;
ll sum[maxn][30];
ll place[maxn][30];
int val[maxn];

int main(){
    ios::sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;
	
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    	place[i][0] = val[i] - 1;
    	sum[i][0] = val[i];
    }

    for(int i = 1; i < 30; i++){
    	for(int j = 0; j < n; j++){
    		place[j][i] = place[place[j][i - 1]][i - 1];
    		sum[j][i] = sum[j][i - 1] + sum[place[j][i - 1]][i - 1];
    	}
    }

    for(int i = 0; i < n; i++){
		ll res = 0;

		ll ind = i;
		ll copy_t = t;
		for(ll j = 29, bit = (1 << 29); j >= 0; j--, bit /= 2){
			if(bit <= copy_t){
				res += sum[ind][j];
				ind = place[ind][j];
				copy_t -= bit;
			}
		}

		cout << res << ' ';
    }
}
