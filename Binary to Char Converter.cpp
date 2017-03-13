#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	string s;
	while(cin >> s){
		int v = 0;
		for(int i = s.size() - 1, bit = 1; i >= 0; i--, bit *= 2){
			if(s[i] == '1'){
				v += bit;
			}
		}

		cout << (char) v;
	}
}