#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int vala[maxn];
int valb[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int y, x;
	int k;
	cin >> y >> x;
	cin >> k;

	for(int i = 0; i < y; i++){
		cin >> vala[i];
	}
	for(int i = 0; i < x; i++){
		cin >> valb[i];
	}

	int pairs = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(abs(vala[i] - valb[j]) >= k){
				pairs++;
			}
		}
	}

	cout << pairs;
}

