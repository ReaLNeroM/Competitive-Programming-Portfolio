#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

class LaserBeam {
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }

        return gcd(b, a % b);
    }
public:
    int calculateNumberOfEnteredCells(int x1, int y1, int x2, int y2){
        x2 -= x1;
        y2 -= y1;

        if(x2 < 0){
            x2 *= -1;
        }
        if(y2 < 0){
            y2 *= -1;
        }

        return (x2 + y2 - gcd(x2, y2));
    }
};