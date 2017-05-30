#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 40;
ll sum[maxn];

char dfs(int step, int pos){
	if(step == 2){
		return 'c';
	} else if(step == 1){
		return 'b';
	} else if(step == 0){
		return 'a';
	}

	if(pos < sum[step - 1]){
		return dfs(step - 1, pos);
	} else if(pos < sum[step - 1] + sum[step - 2]){
		return dfs(step - 2, pos - sum[step - 1]);
	} else {
		return dfs(step - 3, pos - sum[step - 1] - sum[step - 2]);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n, k;
	std::cin >> n >> k;
	k--;
	
	sum[0] = sum[1] = sum[2] = 1;

	for(int i = 3; i <= n; i++){
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
	
	if(k >= sum[n]){
	    std::cout << -1 << std::endl;
	    return 0;
	}

	std::cout << dfs(n, k);
}