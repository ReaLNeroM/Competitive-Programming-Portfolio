#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		string s;
		cin >> s;

		string res = "";
		res += s[0];

		for(int i = 1; i < s.size(); i++){
			if(res[0] <= s[i]){
				res.insert(res.begin(), s[i]);
			} else {
				res += s[i];
			}
		}

		cout << "Case #" << i + 1 << ": ";
		cout << res << endl;
	}
}