#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

class Darts {
public:
    std::string finalResult(std::vector<int> pA, std::vector<int> pB){
        int a_left = 301, b_left = 301;
        
        for(int i = 0; i < pA.size(); i += 3){
            int prev = a_left;
            for(int j = i; j < i + 3; j++){
                a_left -= pA[j];
                if(a_left < 0){
                    a_left = prev;
                    break;
                }
                if(a_left == 0){
                    break;
                }
            }
            if(a_left == 0){
                break;
            }

            prev = b_left;
            for(int j = i; j < i + 3; j++){
                b_left -= pB[j];
                if(b_left < 0){
                    b_left = prev;
                    break;
                }
                if(b_left == 0){
                    break;
                }
            }
            if(b_left == 0){
                break;
            }
        }

        std::string s = "";

        do {
            s += (char) ('0' + (b_left % 10));
            b_left /= 10;
        } while(b_left);
        s += ':';
        do {
            s += (char) ('0' + (a_left % 10));
            a_left /= 10;
        } while(a_left);

        std::reverse(s.begin(), s.end());
        return s;
    }
};