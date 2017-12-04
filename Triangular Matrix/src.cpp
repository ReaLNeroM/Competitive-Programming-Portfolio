#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3005;
std::string s[maxn];
int dp[maxn][maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
    	std::cin >> s[i];
    }

    for(int i = 1; i < n; i++){
    	char smallest = 'z';
    	for(int j = 0; j <= i; j++){
    		if((j != 0 and dp[i - 1][j - 1]) or dp[i - 1][j]){
    			dp[i][j] = true;
    			smallest = std::min(smallest, s[i][j]);
    		}
    	}

    	for(int j = 0; j <= i; j++){
    		if(s[i][j] != smallest){
    			dp[i][j] = false;
    		}
    	}
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j <= i; j++){
    		if(dp[i][j]){
    			std::cout << s[i][j];
    			break;
    		}
    	}
    }
}