#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int val[maxn];
int indices[maxn];
bool used[maxn];
ll res = 0;

bool cmp(int a, int b){
	return val[a] > val[b];
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		indices[i] = i;
	}

	std::sort(indices, indices + n, cmp);
	bool possible = true;

	for(int i = 1; i < n; i++){
		if(val[i] - val[i - 1] > 1){
			possible = false;
		}
	}

	for(int i = 0; i < n; i++){
		int start_from = indices[i] - val[indices[i]];
		if(start_from < 0){
			possible = false;
			break;
		} 

		if(!used[start_from]){
			used[start_from] = true;
			res += (ll) val[indices[i]];
		}
	}

	if(!possible){
		std::cout << "-1\n";
		return 0;
	}

	std::cout << res << '\n';

 }