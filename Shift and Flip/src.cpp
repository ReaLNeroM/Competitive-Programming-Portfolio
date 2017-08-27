#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2005;

int main(){
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	bool possible = false;
	for(char i : b){
		if(i == '1'){
			possible = true;
		}
	}

	if(!possible){
		cout << "-1\n";
		return 0;
	}

	int n = a.size();

	int res = n * n;

	for(int i = 0; i < n; i++){
		int apos = i, bpos = 0;

		int l = 0, r = 0;

		while(bpos < n){
			if(a[apos] != b[bpos]){

			}
			apos = (apos + 1) % n;
			bpos++;
		}

		//da namestes na 0
		//da izvrtes

		//da izvrtes
		//otidi na 0
	}

	std::cout << res << '\n';
}