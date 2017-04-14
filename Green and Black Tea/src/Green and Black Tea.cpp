#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, a, b;
	cin >> n >> k >> a >> b;

	string s = "";
	for(int i = 0; i < n; i++){
		if(a >= b){
			s += 'G';
		} else {
			s += 'B';
		}
	}

	if(min(a, b) != 0){
		int left = min(a, b);
		for(int start = k; start >= 0; start -= 2){
			for(int i = start; i < n and left; i += k + 1){
				if(a < b){
					s[i] = 'G';
					left--;
				} else {
					s[i] = 'B';
					left--;
				}
			}
		}
		for(int start = k - 1; start >= 0; start -= 2){
			for(int i = start; i < n and left; i += k + 1){
				if(a < b){
					s[i] = 'G';
					left--;
				} else {
					s[i] = 'B';
					left--;
				}
			}
		}
	}

	int run = 1;
	int type_run = (s[0] == 'G') ? 0 : 1;
	for(int i = 1; i < n; i++){
		if(type_run != ((s[i] == 'G') ? 0 : 1)){
			if(run > k){
				cout << "NO" << endl;
				return 0;
			}
			type_run = !type_run;
			run = 1;
		} else {
			run++;
		}
	}
	if(run > k){
		cout << "NO" << endl;
		return 0;
	}

	cout << s;
}
