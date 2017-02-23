#include <vector>
#include <cmath>

typedef long long ll;

class PointDistance{
	struct coordinate {
		int x, y;
	} transfer;
	double euclidd(coordinate x, coordinate y){
	    return std::sqrt(std::pow(std::abs((double) x.x - y.x), 2) + std::pow(std::abs((double) x.y - y.y), 2));
	}

public:
	std::vector<int> findPoint(int x1, int y1, int x2, int y2){
		coordinate first, second, curr;
		first.x = x1 + 100, first.y = y1 + 100;
		second.x = x2 + 100, second.y = y2 + 100;

		std::vector<int> res(2);
		for(int i = 0; i <= 200; i++){
			curr.x = i;
			for(int j = 0; j <= 200; j++){
				curr.y = j;
				if(curr.x == first.x and curr.y == first.y){

				} else if(curr.x == second.x and curr.y == second.y){

				} else if(euclidd(curr, second) + 0.00000001 < euclidd(curr, first)){
					res[0] = curr.x - 100, res[1] = curr.y - 100;
					return res;
				}
			}
		}
		return res;
	}
};
