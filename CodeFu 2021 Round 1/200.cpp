// https://codefu.mk/codefu2021-round1.html?subpage=problem&problemid=3213

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

class SpaceTravel {
public:
    int findTimestep(vector<string> ka, vector<string> kr){
        int f = -1;
        for(int i = 0; i < kr.size(); i++){
            if(kr[i] == "Eset"){
                f = i + 1;
                break;
            }
        }

        int currPos = 0;
        int time = 1;
        while(time <= 10000){
            if(ka[currPos] == "Eset" and f <= time){
                return time - f + 1;
            }

            time++;
            currPos = (currPos + 1) % ka.size();
        }

        return time;
    }
};
