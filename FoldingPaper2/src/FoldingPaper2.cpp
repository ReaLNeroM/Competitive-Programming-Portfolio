#include <iostream>
#include <vector>
#include <cmath>

class NineEasy{
public:
	int count(int N, std::vector<int> d){
		N += d[0];
		return 0;
	}
};
int main() {
	FoldingPaper2 a;
	std::cout << a.solve(4, 4, 1);
	return 0;
}
