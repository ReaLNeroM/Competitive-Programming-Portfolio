#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	std::string str1, str2;
	cin >> str1 >> str2;

	int s1 = 0;
	int s2 = 0;
	while(s1 < str1.length() and str1[s1] == '0'){
		s1++;
	}
	while(s2 < str2.length() and str2[s2] == '0'){
		s2++;
	}

	if(str1.length() - s1 > str2.length() - s2){
		cout << '>';
	} else if(str1.length() - s1 < str2.length() - s2){
		cout << '<';
	} else {
		int j;
		for(j = 0; j < str1.length() - s1; j++){
			if(str1[s1 + j] > str2[s2 + j]){
				cout << '>';
				break;
			} else if(str1[s1 + j] < str2[s2 + j]){
				cout << '<';
				break;
			}
		}
		if(j == str1.length() - s1){
			cout << '=';
		}
	}
	return 0;
}
