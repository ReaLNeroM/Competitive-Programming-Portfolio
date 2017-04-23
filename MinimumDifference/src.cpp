#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>

class MinimumDifference{
	int n, k;
	int diff(std::string a, std::string b){
		int sum = 0;
		for(int i = k - 1, pow = 1; i >= 0; i--, pow *= 10){
			sum += (a[i] - '0') * pow;
		}
		for(int i = k - 1, pow = 1; i >= 0; i--, pow *= 10){
			sum -= (b[i] - '0') * pow;
		}

		return std::abs(sum);
	}
  public:
    int compute(int nn, int kk, std::vector<std::string> numbers){
    	n = nn, k = kk;
    	int board[k];
    	for(int i = 0; i < k; i++){
    		board[i] = i;
    	}

    	int best = 1e9;
    	do {
    		std::vector<std::string> sec = numbers;

    		for(int i = 0; i < n; i++){
    			for(int j = 0; j < k; j++){
    				sec[i][j] = numbers[i][board[j]];
    			}
    		}

    		int curr = 0;
    		for(int i = 0; i < n; i++){
    			for(int j = i + 1; j < n; j++){
    				curr = std::max(curr, diff(sec[i], sec[j]));
    			}
    		}

    		best = std::min(best, curr);
    		if(!std::next_permutation(board, board + k)){
    			break;
    		}
    	} while(true);

    	return best;
  	}
};