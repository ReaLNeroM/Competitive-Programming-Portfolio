#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>

class IpAddresses{
	const int mod = 1e9 + 7;
	int size, b;
	std::string s;
	int dp[105][105];
	int dfs(int a, int left){
		if(dp[a][left] == -1){
			if(a == size){
				if(left == 0){
					dp[a][left] = 1;
				} else {
					dp[a][left] = 0;
				}
			} else {
				dp[a][left] = 0;
				int formed = 0;
				for(int i = a; i < a + 3 and i < s.size(); i++){
					formed *= 10;
					formed += (s[i] - '0');
					if(formed > 255){
						break;
					}		
					dp[a][left] += dfs(i + 1, left - 1);
					dp[a][left] %= mod;		
					if(i == a and formed == 0){
						break;
					}
				}
			}
		}

		return dp[a][left];
	}

  public:
  	int count(std::string a, int bb){
  		size = a.size();
  		s = a;
  		b = bb;

  		for(int i = 0; i < 105; i++){
  			for(int j = 0; j < 105; j++){
  				dp[i][j] = -1;
  			}
  		}

  		return dfs(0, b);
  	}
};