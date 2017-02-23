#include <iostream>
#include <vector>

static int dp[1050000];

class OrderofOperationsDiv2{
	int size;
	std::vector<int> oper;
public:

	int check(int bitmask) {
	  if (dp[bitmask] == -1){
		  dp[bitmask] = 2000000;
		  for (int i = 0; i < oper.size(); i++) {
			  if (bitmask != (bitmask | oper[i])){
				  int cost = 0;
				  for(int j = 0, bitset = 1; j < size; j++, bitset *= 2){
					  if((bitset & bitmask) != (bitset & oper[j])){
						  cost++;
					  }
				  }

				  cost *= cost;
				  dp[bitmask] = std::min(dp[bitmask], cost + check(bitmask | oper[i]));
			  }
		  }
	  }

	  return dp[bitmask];     // Storing the best dist for the set of traveled cities and untraveled ones.
	}

	int minTime(std::vector<std::string> s){
		size = s[0].size();
		for(int i = 0; i < (1 << size); i++){
			dp[i] = -1;
		}
		dp[(1 << size) - 1] = 0;

		oper.resize(s.size());
		for(int i = 0; i < s.size(); i++){
			int copy = 0;
			for(int j = 0; j < s[i].length(); j++){
				copy *= 2;
				if(s[i][j] == '1'){
					copy++;
				}
			}

			oper[i] = copy;
		}

		return check(0);
	}
};

int main() {
	int size;
	std::cin >> size;
	std::vector<std::string> s(size);
	for(int i = 0; i < size; i++){
		std::cin >> s[i];
	}

	OrderofOperationsDiv2 X;
	std::cout << X.minTime(s);
	return 0;
}
