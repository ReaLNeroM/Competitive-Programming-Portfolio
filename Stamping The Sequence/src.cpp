#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
    	std::vector<int> res;
    	int tagged[target.length()];
    	memset(tagged, 0, sizeof(tagged));

    	for(int i = 0; i + stamp.length() <= target.size(); i++){
    		if(!tagged[i] and target.substr(i, stamp.length()) == stamp){
    			tagged[i] = true;
    			res.push_back(i);
    			int lastpos = i;
    			for(int j = i - 1; j >= 0; j--){
    				if(!tagged[j] and target.substr(j, lastpos - j) == stamp.substr(0, lastpos - j)){
    					tagged[j] = true;
    					res.push_back(j);
    					lastpos = j;
    				}
    			}
    			lastpos = i + stamp.length();
    			for(int j = i + 1; j < target.length(); j++){
    				bool equal = true;
    				for(int k = lastpos; k < j + stamp.length(); k++){
    					if(target[k] != stamp[k - j]){
    						equal = false;
    					}
    				}

    				if(!tagged[j] and equal){
    					tagged[j] = true;
    					res.push_back(j);
    					lastpos = j + stamp.length();
    				}
    			}
    		}
    	}
    
    	bool satisfy[target.length()];
    	memset(satisfy, 0, sizeof(satisfy));
    	for(int i = 0; i < target.length(); i++){
    		if(tagged[i]){
    			for(int j = 0; j < stamp.length() and i + j < target.length(); j++){
    				satisfy[i + j] = true;
    			}
    		}

    		if(!satisfy[i]){
    			return std::vector<int>();
    		}
    	}
    	std::reverse(res.begin(), res.end());
    	return res;
    }
};