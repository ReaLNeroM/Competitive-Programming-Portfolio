#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>

class Brackets{
  public:
    int longest(std::string brackets){
    	int open = 0;

    	int size = 0;
    	for(int i = 0; i < brackets.size(); i++){
    		if(brackets[i] == '['){
    			open++;
    		} else {
    			if(open > 0){
    				open--;
    				size += 2;
    			}
    		}
    	}
    	return size;
  	}
};