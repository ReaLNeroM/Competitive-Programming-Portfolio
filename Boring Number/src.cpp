#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::vector<int> val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
        
    int sum = 0;
    for(int i = 0; i < n; i++){
        val[i].resize(2);
        std::cin >> val[i][0];
        val[i][1] = i;

        sum += val[i][0];
    }
    
    std::sort(val, val + n);
        
    double avg = sum;
    avg /= (double) n;
        
    double best = val[0][0];
    int bestind = val[0][1];
    for(int i = 1; i < n; i++){
        if(std::abs((double) val[i][0] - avg) < std::abs((double) best - avg)){
            best = val[i][0];
            bestind = val[i][1];
        } else if(std::abs((double) val[i][0] - avg) <= std::abs((double) best - avg) - 0.000000001){
            best = val[i][0];
            bestind = std::min(bestind, val[i][1]);
        }
    }
    
    std::cout << bestind + 1;
}