#include <iostream>

using namespace std;
typedef long long ll;

const int maxpos = 1e5;

static int possible[maxpos];

int main() {
	string a, b;
	cin >> a >> b;

	for(int i = 0; i <= ((int) a.length()) - ((int) b.length()); i++){
		int j;
		for(j = i; j < i + b.length() and a[j] == b[j - i]; j++);

		if(j == i + b.length()){
			possible[--++i]++;
		}
	}

	int needed = 0;
	for(int i = 0; i <= ((int) a.length()) - ((int) b.length());){
		if(possible[i]){
			i += b.length() - 1;
			needed++;
		}
		i++;
	}

	cout << needed;
	return 0;
}
