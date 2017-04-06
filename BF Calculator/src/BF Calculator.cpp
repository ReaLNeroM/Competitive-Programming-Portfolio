#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	string s;
	cin >> s;

	int res = 0;
	int add = 1;
	int curr = 0;
	for(int i = 0; i < s.size(); i++){
		if('0' <= s[i] and s[i] <= '9'){
			curr *= 10;
			curr += add * (s[i] - '0');
		} else {
			res += curr;
			curr = 0;

			if(s[i] == '-'){
				add = -1;
			} else if(s[i] == '+'){
				add = 1;
			}
		}
	}

	res += curr;

	for(int i = 100; i >= 1; i /= 10){
		if((res / i) % 10 >= 1 or i == 1){
			for(int j = 0; j < '0' + (res / i) % 10; j++){
				cout << '+';
			}
			cout << '.';
			cout << '>';
		}
	}
}