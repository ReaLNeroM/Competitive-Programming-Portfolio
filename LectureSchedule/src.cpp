#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long ll;

class LectureSchedule {
	std::vector<int> start, end;
public:
	ll dp[200][200];
	ll n;

	ll dpfunc(ll a, ll b){
		if(dp[a][b] == -1){
			ll& ans = dp[a][b];

			ans = 0;

			for(ll new_a = a; new_a < n; new_a++){
				for(ll new_b = b; new_b < n; new_b++){
					if(start[new_a] < end[new_b] and (b == 0 or end[b - 1] <= start[new_a])){
						ans = std::max(ans, dpfunc(new_a + 1, new_b + 1) + 1);
					}
				}
			}
		}

		return dp[a][b];
	}

	int maxLectures(std::vector<int> gstart, std::vector<int> gend){
		n = gstart.size();
		start = gstart;
		end = gend;
		std::sort(start.begin(), start.end());
		std::sort(end.begin(), end.end());
		memset(dp, -1, sizeof(dp));

		return dpfunc(0, 0);
	}
};
