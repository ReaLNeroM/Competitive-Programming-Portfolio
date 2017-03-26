#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int skip5 = (n / 5) + (n / 25) + (n / 125) + (n / 625) + (n / 3125);
	int skip2 = skip5;

	int left = 1;
	for(int i = 2; i <= n; i++){
		int remaining = i;
		while(remaining % 2 == 0 and skip2){
			remaining /= 2;
			skip2--;
		}
		while(remaining % 5 == 0 and skip5){
			remaining /= 5;
			skip5--;
		}
		left *= remaining;
		left %= 10;
	}
	
	cout << left;
}