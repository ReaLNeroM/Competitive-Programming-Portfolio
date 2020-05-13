#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;
int val[maxn];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for(int _t = 0; _t < t; _t++){
		int n, k;
		cin >> n >> k;

		bool all_equal = true;
		bool any_equals_k = false;
		for(int i = 0; i < n; i++){
			cin >> val[i];
			all_equal &= (val[i] == k);
			any_equals_k |= (val[i] == k);

			val[i] = (val[i] >= k) ? 1 : -1;
		}

		bool positive_adjacents = false;
		for(int i = 0; i < n; i++){
			if(i < n - 1 and val[i] == 1 and val[i + 1] == 1){
				positive_adjacents = true;
			} else if(i < n - 2 and val[i] == 1 and val[i + 1] == -1 and val[i + 2] == 1){
				positive_adjacents = true;
			}
		}

		cout << (((any_equals_k and positive_adjacents) or all_equal) ? "yes" : "no") << '\n';
	}	
}