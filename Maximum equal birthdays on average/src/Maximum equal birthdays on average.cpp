#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int days = 365;
const int maxn = 1000000;
const int tries = 100000;
int val[days];
int resfound[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0));

	for(int n = 1; n <= 1000; n++){
		for(int i = 0; i <= n; i++){
			resfound[i] = 0;
		}
		for(int i = 0; i < tries; i++){
			for(int j = 0; j < days; j++){
				val[j] = 0;
			}

			for(int j = 0; j < n; j++){
				int rr = rand() % days;
				val[rr]++;
			}

			int biggest = 0;
			for(int j = 0; j < days; j++){
				biggest = max(biggest, val[j]);
			}
			resfound[biggest]++;
		}

		double avg = 0.0;
		for(int i = 0; i <= n; i++){
			avg += resfound[i] * i;
		}

		cout << avg / (double) tries << endl;
	}
}

