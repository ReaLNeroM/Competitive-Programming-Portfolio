#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int max_sq = 320;

int val[maxn];
std::deque<int> block[2 * max_sq];
int start[2 * max_sq];
int size[2 * max_sq];
int reverse[2 * max_sq];

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> val[i];
		val[i]--;
	}

	int sq = sqrt(n) + 1;

	for(int i = 0; i < n; i += sq){
		block[i].resize(sq);
		for(int j = i; j < i + sq and j < n; j++){
			location[val[j]] = i;
			block[i].push_back(val[j]);
		}
	}

	for(int i = 0; i < n; i++){
		int last = location[i];

		for(int j = 0; j < 2 * max_sq; j++){

		}
	}
}