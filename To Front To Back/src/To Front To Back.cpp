#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int val[maxn];
int v[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> val[i];
		v[val[i] - 1] = i;
	}
	
	int run = 1;
	int best_run = 0;
	int best_start = 0;
	int best_end = 0;
	for(int i = 1; i < n; i++){
		if(v[i - 1] < v[i]){
			run++;
			if(run > best_run){
				best_run = run;
				best_start = i - run + 1;
				best_end = i;
			}
		} else {
			run = 1;
		}
	}
	
	cout << n - run << endl;
	for(int i = 0; i < n; i++){
		if(i < best_start){
			cout << i << ' ' << 0 << endl;
		} else if(best_end < i){
			cout << i << ' ' << 1 << endl;
		}
	}
}
