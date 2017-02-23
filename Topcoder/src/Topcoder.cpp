#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

class BearChairs{
public:
	vector<int> findPositions(vector<int> atLeast, int d){
		vector<int> v;

		vector<int> order;
		order.push_back(atLeast[0]);
		v.push_back(atLeast[0]);

		for(int i = 1; i < atLeast.size(); i++){
			int j;
			for(j = 0; j < i - 1; j++){
				if(order[j] <= atLeast[i] and atLeast[i] <= order[j + 1]){
					break;
				}
			}

			for(; j < i - 1; j++){
				if(order[j] + d <= atLeast[i] and atLeast[i] <= order[j + 1] - d){
					order.push_back(order[j] + d);
					v.push_back(order.front());
					break;
				}
			}

			if(j == i - 1){
				v.push_back(order.front());
				order.push_back(order[order.size() - 1] + d);
			}

			sort(order.begin(), order.end());
		}

		return v;
	}
};
