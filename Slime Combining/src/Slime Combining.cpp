#include <iostream>

typedef long long ll;
using namespace std;

static int val[100000];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	val[0] = 1;
	int pos = 1;
	for(int i = 1; i < n; i++){
		val[pos] = 1;
		while(pos > 0 and val[pos - 1] == val[pos]){
			val[pos - 1]++;
			val[pos] = 0;
			pos--;
		}
		pos++;
	}

	for(int i = 0; i < pos; i++){
		cout << val[i] << ' ';
	}
	return 0;
}
