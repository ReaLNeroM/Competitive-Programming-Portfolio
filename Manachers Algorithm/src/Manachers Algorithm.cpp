#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int even[maxn];
int odd[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;

	int n = s.size();
	
	int l = -1, r = -1;
	for(int i = 0; i < n; i++){
		if(i > r){
			odd[i] = 1;
		} else {
			odd[i] = min(odd[l + r - i], r - i) + 1;
		}

		while(0 <= i - odd[i] - 1 and i + odd[i] + 1 < n and s[i - odd[i] - 1] == s[i + odd[i] + 1]){
			odd[i]++;
		}

		if(i + odd[i] - 1 > r){
			l = i - odd[i] + 1;
			r = i + odd[i] - 1;
		}
	}
	
	l = r = -1;
	for(int i = 0; i < n; i++){
		if(i > r){
			even[i] = 0;
		} else {
			even[i] = min(even[l + r - i + 1], r - i - 1);
		}

		while(0 <= i - even[i] - 2 and i + even[i] + 1 < n and s[i - even[i] - 2] == s[i + even[i] + 1]){
			even[i]++;
		}

		if(i + odd[i] - 1 > r){
			l = i - odd[i] + 1 - 1;
			r = i + odd[i] + 1;
		}
	}
}
