#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + n);

	int power_2 = val[n - 1];
	while(power_2 - (power_2 & (-power_2)) > 0){
		power_2 -= power_2 & -power_2;
	}
	
	int generated = 0;
	for(int i = power_2; i >= 1; i /= 2){
		generated |= i;
		int found = 0;
		for(int j = 0; j < n; j++){
			if((generated & val[j]) == generated){
				found++;
			}
		}

		if(found >= k){
		} else {
			generated -= i;
		}
	}

	cout << generated;
	
}
