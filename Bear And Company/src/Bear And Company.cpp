#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int res = 0;
	for(int i = 0; true; i++){
		bool operation = false;
		for(int j = 1; j + 1 < s.size() and !operation; j++){
			if(s[j - 1] != 'V' and s[j - 1] != 'K' and s[j] == 'V' and s[j + 1] == 'K'){
				swap(s[j - 1], s[j]);
				operation = true;
				res++;
			}
		}
		for(int j = 0; j + 2 < s.size() and !operation; j++){
			if(s[j + 2] != 'V' and s[j + 2] != 'K' and s[j] == 'V' and s[j + 1] == 'K'){
				swap(s[j + 1], s[j + 2]);
				operation = true;
				res++;
			}
		}
		for(int j = 0; j + 1 < s.size() and !operation; j++){
			if(s[j] == 'V' and s[j + 1] == 'K'){
				swap(s[j], s[j + 1]);
				operation = true;
				res++;
			}
		}
		if(!operation){
			break;
		}
	}

	cout << res;
}