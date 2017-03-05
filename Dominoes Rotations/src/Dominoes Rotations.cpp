#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
pair<int, int> val[maxn];
int dp[maxn][2];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> val[i].first >> val[i].second;
    }
    for(int i = 0; i < maxn; i++){
    	for(int j = 0; j < 2; j++){
    		dp[i][j] = 1e9;
    	}
    }
    dp[0][0] = 0, dp[0][1] = 1;

    for(int i = 1; i < n; i++){
    	if(val[i].first == val[i - 1].second){
    		dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    	}
    	if(val[i].first == val[i - 1].first){
    		dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    	}
    	if(val[i].second == val[i - 1].first){
    		dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
    	}
    	if(val[i].second == val[i - 1].second){
    		dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
    	}
    }

    if(min(dp[n - 1][0], dp[n - 1][1]) == 1e9){
    	cout << -1;
    } else {
    	cout << min(dp[n - 1][0], dp[n - 1][1]);
    }
}
