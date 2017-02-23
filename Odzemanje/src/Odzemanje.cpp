//============================================================================
// Name        : Odzemanje.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	string fr;
	cin >> fr;
	sort(fr.begin(), fr.end(), greater<int>());
	string se = fr;
	reverse(se.begin(), se.end());
	string res = fr;

	if(se == fr){
		cout<<0;
		return 0;
	}
	for (int i = fr.length() - 1; i >= 0; i--) {
		if (fr[i] >= se[i]) {
			res[i] = fr[i] - se[i];
		} else {
			for (int copier = i - 1; true; copier--) {
				if (fr[copier] != 0) {
					fr[copier]--;
					break;
				} else{
					fr[copier] = 57;
				}
			}
			res[i] = 58 + fr[i] - se[i];
		}
	}
	bool started = false;
	for (int i = 0; i < res.length(); i++) {
		if (res[i] < 48) {
			res[i] += 48;
		}
		if(res[i] == 48 and !started){
			continue;
		}
		cout << res[i];
		started = true;
	}

	if(res.length() == 1){
		cout<<0;
	}
	return 0;
}
