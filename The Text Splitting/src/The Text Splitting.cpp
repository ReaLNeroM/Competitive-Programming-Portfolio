#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n, f, s;
	cin >> n >> f >> s;

	int used;
	for(used = 0; used < n; used += f){
		if((n - used) % s == 0){
			break;
		}
	}

	string str;
	cin >> str;

	if(used > n){
		cout << -1;
	} else {
		cout << used / f + (n - used) / s << endl;
		for(int i = 0; i < used; i += f){
			for(int j = i; j < i + f; j++){
				cout << str[j];
			}
			cout << endl;
		}
		for(int i = used; i < n; i += s){
			for(int j = i; j < i + s; j++){
				cout << str[j];
			}
			cout << endl;
		}
	}
	return 0;
}
