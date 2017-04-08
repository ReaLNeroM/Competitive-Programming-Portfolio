#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		string s;
		cin >> s;

		int flipper;
		cin >> flipper;

		int res = 0;
		bool good = true;

		for(int i = 0; i < s.size(); i++){
			if(s[i] == '-' and i + flipper <= s.size()){
				res++;
				for(int j = i; j < i + flipper; j++){
					if(s[j] == '-'){
						s[j] = '+';
					} else {
						s[j] = '-';
					}
				}
			} else if(s[i] == '-'){
				good = false;
			}
		}

		cout << "Case #" << x + 1 <<": ";
		if(!good){
			cout << "IMPOSSIBLE\n";
		} else {
			cout << res << endl;
		}
	}
}

