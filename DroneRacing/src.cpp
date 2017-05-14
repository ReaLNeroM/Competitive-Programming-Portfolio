#include <string>
#include <vector>
using namespace std;

class DroneRacing{
public:
    int winner(int N, string races){
    	vector<int> v;
    	for(int i = 1; i <= N; i++){
    		v.push_back(i);
    	}

    	int racespos = 0;
    	
    	while(v.size() > 1){
    		int l = 0, r = v.size() - 1;
    		vector<int> nnew = v;
    		int lpos = 0, rpos = v.size() - 1;

    		while(l < r){
    			if(races[racespos] == '1'){
    				nnew.erase(nnew.begin() + rpos);
    				rpos--;
    				lpos++;
    			} else {
    				nnew.erase(nnew.begin() + lpos);
    				rpos -= 2;
    			}

    			racespos++;
    			l++, r--;
    		}

    		v = nnew;
    	}

    	return v[0];
 	}
};