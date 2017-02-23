#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	string specialval = "";
	int zeroes = 0;
	for(int i = 0; i < n; i++){
		string val;
		cin >> val;

		bool special = false;
		int zeroval = 0;

		if(val[0] != '1'){
			special = true;
		}
		for(int j = 1; j < val.size(); j++){
			if(val[j] != '0'){
				special = true;
			}
		}

		if(specialval != "0"){
			if(val == "0" or special){
				specialval = val;
			} else {
				zeroes += val.size() - 1;
			}
		}
	}

	if(specialval == "0"){
		cout << "0";
	} else {
		if(specialval == ""){
			cout << '1';
		}
		cout << specialval;
		for(int i = 0; i < zeroes; i++){
			cout << '0';
		}
	}
	return 0;
}
