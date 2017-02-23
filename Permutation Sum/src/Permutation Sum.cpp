#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool used[16], a[16], b[16];
int n;

int dfs(int pos){
	ll res;
	if(pos == n){
		res = 1;
	} else {
		res = 0;
		for(int i = 0; i < n; i++){
			if(!a[i]){
				a[i] = true;

				for(int j = 0; j < n; j++){
					if(!b[j]){
						b[j] = true;
						int sum = i + j;
						if(sum >= n){
							sum -= n;
						}
						if(!used[sum]){
							used[sum] = true;
							res += dfs(pos + 1);
							used[sum] = false;
						}
						b[j] = false;
					}
				}

				a[i] = false;
			}
		}
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i = 0; i < n; i++){
		used[i] = a[i] = b[i] = false;
	}
	cout << dfs(0);

	return 0;
}
