#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		string s;
		cin >> s;

		cout << "Case #" << x + 1 << ": " << s << ' ';

		bool good = true;
		for(int i = 1; i < s.size(); i++){
			if(s[i - 1] > s[i]){
				good = false;
			}
		}
		if(good){
			cout << s << '\n';
			continue;
		}

		string other = "";
		for(int i = 0; other.size() < s.size(); i++){
			other += '9';
		}

		if(other > s){
			other.erase(--other.end());
		}

		for(int i = 0; i < s.size(); i++){
			string nnew = s;
			nnew[i]--;
			for(int j = i + 1; j < nnew.size(); j++){
				nnew[j] = '9';
			}
			bool good = true;
			while(nnew[0] == '0'){
				nnew.erase(nnew.begin());
			}
			for(int j = 1; j < nnew.size(); j++){
				if(nnew[j - 1] > nnew[j]){
					good = false;
				}
			}
			if(good){
				if(other.size() < nnew.size() or (other.size() == nnew.size() and other < nnew)){
					other = nnew;
				}
			}
		}

		cout << other;
		cout << '\n';
	}
}

