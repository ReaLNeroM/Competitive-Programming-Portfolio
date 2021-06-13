#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

class NiceLists {
public:
    int makeNice(vector<int> A, vector<int> B, int n){
    	std::vector<int> v;
    	for(int i = 0; i < n; i++){
    		if(((A[i] + B[i]) % 2) == 1){
    			v.push_back(i);
    		}
    	}
    	if(v.size() % 2 != 0){
    		return -1;
    	}
    	int res = 0;
    	for(int i = 0; i < v.size(); i += 2){
    		res += v[i + 1] - v[i];
    	}
    	return res;
	}
};
	