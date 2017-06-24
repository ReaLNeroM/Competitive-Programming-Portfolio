#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 505;
const int INF = 1e9 + 1e2;
const int mod = 1e9 + 7;

int dp[maxn][2 * maxn];
int comp[2 * maxn];
int a[maxn], b[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> a[i] >> b[i];
		m[a[i] - 1] = 1;
		m[b[i]] = 1;
	}
	m[INF] = 1;

	int intervals = 0;
	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = intervals;
		comp[intervals] = ite->first;
		intervals++;
	}
	
	dp[n][intervals - 1] = 1;

	for(int i = n - 1; i >= 0; i--){
		for(int j = intervals - 1; j >= 0; j--){
			if(a[i] <= comp[j] and comp[j] <= b[i]){
				
			}
		}
	}

	std::cout << dp[0][0] << std::endl;
}