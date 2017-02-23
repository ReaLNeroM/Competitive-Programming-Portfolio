#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int a, b, ma, mb;
	cin >> a >> b >> ma >> mb;

	a = max(3 * a / 10, a - a/250 * ma);
	b = max(3 * b / 10, b - b/250 * mb);

	if(a > b){
		cout << "Misha";
	} else if(a < b){
		cout << "Vasya";
	} else {
		cout << "Tie";
	}
	return 0;
}
