#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int need = n / 4;

	if(n % 4 != 0){
		cout << "===" << endl;
		return 0;
	}

	int found[] = {0, 0, 0, 0};
	char val[] = {'A', 'C', 'G', 'T'};

	string s;
	cin >> s;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			if(s[i] == val[j]){
				found[j]++;
			}
		}
	}

	for(int i = 0; i < 4; i++){
		int changes_needed = need - found[i];
		for(int j = 0; j < n; j++){
			if(s[j] == '?' and changes_needed > 0){
				s[j] = val[i];
				changes_needed--;
			}
		}

		if(changes_needed != 0){
			cout << "===" << endl;
			return 0;
		}
	}

	cout << s;
}

