#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	int books, genres;
	cin >> books >> genres;

	int t[genres];
	for(int i = 0; i < genres; i++){
		t[i] = 0;
	}

	for(int i = 0, b; i < books; i++){
		cin >> b;
		t[b - 1]++;
	}

	int sum = books, res = 0;
	for(int i = 0; i < genres; i++){
		sum -= t[i];
		res += sum * t[i];
	}

	cout << res;
	return 0;
}
