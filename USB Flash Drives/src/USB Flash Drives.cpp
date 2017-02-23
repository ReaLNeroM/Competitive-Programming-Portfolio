#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
	int usb, size;
	cin >> usb >> size;

	int drive[usb];
	for(int i = 0; i < usb; i++){
		cin >> drive[i];
	}
	sort(drive, drive + usb, greater<int>());

	int i;
	for(i = 0; i < usb and size > 0; i++){
		size -= drive[i];
	}

	cout << i;
	return 0;
}
