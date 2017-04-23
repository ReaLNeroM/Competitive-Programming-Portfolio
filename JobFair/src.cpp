#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>

class JobFair{
public:
	int maxStands(std::vector<int> startingStand, std::vector<int> endingStand, int N){
		int n = startingStand.size();
		int overlap[n];
		std::fill(overlap, overlap + n, false);

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(endingStand[i] < startingStand[j] or endingStand[j] < startingStand[i]){
				} else {
					overlap[i] = true, overlap[j] = true;
				}
			}
		}

		int found = 0;
		for(int i = 0; i < n; i++){
			if(!overlap[i]){
				found++;
			}
		}
		return found;
	}
};
