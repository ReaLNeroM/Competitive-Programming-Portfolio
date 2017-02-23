#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	string str;
	cin >> str;

	int left[4];
	for(int i = 0; i < 4; i++){
		left[i] = 0;
	}

	char op[] = {'(', '[', '{', '<'};
	char cl[] = {')', ']', '}', '>'};
	int changed = 0;

	for(int i = 0; i < str.length(); i++){
		for(int j = 0; j < 4; j++){
			if(str[i] == op[j]){
				left[j]++;
			}
			if(str[i] == cl[j]){
				if(left[j] > 0){
					left[j]--;
				} else {
					for(int k = 0; k < 4; k++){
						if(left[k] > 0){
							left[k]--;
							changed++;
							break;
						}
						if(k == 3){
							cout << "Impossible";
							return 0;
						}
					}
				}
			}
		}
	}

	for(int k = 0; k < 4; k++){
		if(left[k] != 0){
			cout << "Impossible";
			return 0;
		}
	}

	cout << changed;
	return 0;
}
