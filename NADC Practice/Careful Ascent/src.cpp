// https://open.kattis.com/contests/nadc21practice1/problems/carefulascent

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e2 + 1e2;
const long double eps = 1e-14;
std::vector<std::pair<std::pair<int, int>, long double>> shields;

int x, y;
int n;

bool overshoot(long double h){
    long double currX = 0.0;
    int currY = 0;

    for(int i = 0; i < n; i++){

        currX += h * ((long double) shields[i].first.first - currY);
        if(currY <= y and y <= shields[i].first.first){
            currY = y;
            break;
        }
        currY = shields[i].first.first;

        h *= shields[i].second;

        currX += h * ((long double) shields[i].first.second - currY);
        if(currY <= y and y <= shields[i].first.second){
            currY = y;
            break;
        }
        currY = shields[i].first.second;

        h /= shields[i].second;
    }

    currX += h * ((long double) y - currY);
    currY = y;

    return currX > x;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    cin >> x >> y;

    std::cin >> n;
    shields.resize(n);

    for(int i = 0; i < n; i++){
        cin >> shields[i].first.first;
        cin >> shields[i].first.second;
        cin >> shields[i].second;
    }

    std::sort(shields.begin(), shields.end());

    long double ub = 1e14;
    long double lb = -ub;

    for(int i = 0; i < 500; i++){
        long double mid = (lb + ub) / 2.0L;

        if(overshoot(mid)){
            ub = mid;
        } else {
            lb = mid;
        }
    }

    std::cout.precision(10);
    cout << std::fixed << lb << '\n';
}
