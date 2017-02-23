#include <iostream>
#include <vector>

int vertices;
std::vector<std::vector<int> > costmatrix;
std::vector<std::vector<int> > memo;

int TSP(int pos, int bitmask) {
  if (bitmask == (1<<vertices)-1){
      return costmatrix[pos][0];
  }

  if (memo[pos][bitmask] == -1){
	  memo[pos][bitmask] = 2000000;
	  for (int i = 0; i < vertices; i++) {
		  if (i != pos && (bitmask & (1 << i)) == 0){
			  memo[pos][bitmask] = std::min(memo[pos][bitmask], costmatrix[pos][i] + TSP(i, bitmask | (1 << i)));
		  }
	  }
  }

  return memo[pos][bitmask];     // Storing the best dist for the set of traveled cities and untraveled ones.
}

int main() {
	std::cin >> vertices;

	for(int i = 0; i < vertices; i++){
		std::vector<int> copy(vertices), mmo(1 << vertices, -1);
		memo.push_back(mmo);
		for(int j = 0; j < vertices; j++){
			std::cin >> copy[j];
		}
		costmatrix.push_back(copy);
	}

	std::cout << TSP(0, 1);
	return 0;
}
