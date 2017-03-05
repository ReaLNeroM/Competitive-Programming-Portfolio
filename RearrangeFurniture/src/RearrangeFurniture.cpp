#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class RearrangeFurniture {
public:
	int lowestEffort(vector<int> weights, vector<int> finalPositions){
		int size = weights.size();
		int last[size];
		for(int i = 0; i < size; i++){
			last[finalPositions[i]] = i;
		}
		int curr[size];
		for(int i = 0; i < size; i++){
			curr[i] = i;
		}

		int res = 0;
		for(int i = 0; i < size; i++){
			int biggest_ind = -1;

			for(int j = 0; j < size; j++){
				if(j != last[curr[j]] and (biggest_ind == -1 or weights[curr[biggest_ind]] < weights[curr[j]])){
					biggest_ind = j;
				}
			}
			if(biggest_ind == -1){
				break;
			}

			res += weights[curr[biggest_ind]] + weights[curr[last[curr[biggest_ind]]]];
			swap(curr[biggest_ind], curr[last[curr[biggest_ind]]]);
		}

		return res;
	}
};
//
//int main(){
//	RearrangeFurniture x;
//	cout << x.lowestEffort({5, 4, 7, 3, 10}, {1, 2, 0, 4, 3});
//
//}
