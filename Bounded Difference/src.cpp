#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
std::vector<int> problem;
ll res = 0;
int n, k;

bool check(int a, int b){
    for(int i = std::max(0, a); i + 1 < n and i + 1 <= b; i++){
        if(std::abs(val[i] - val[i + 1]) > k){
            return false;
        }
    }
    
    return true;
}

bool big_check(){
    for(int i = 0; i < problem.size(); i++){
        if(!check(problem[i] - 2, problem[i] + 3)){
            return false;
        }
    }
    
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    for(int i = 0; i < n - 1; i++){
        if(std::abs(val[i] - val[i + 1]) > k){
            problem.push_back(i);   
        }
    }
    
    if(problem.size() == 0){
        std::cout << 0 << std::endl;
        return 0;
    } else if(problem.size() <= 4){
        for(int i = 0; i < problem.size(); i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < n; k++){
                    std::swap(val[problem[i] + j], val[k]);
                    if(big_check() and check(k - 2, k + 3)){
                        std::cout << problem[i] + j + 1 << ' ' << k + 1 << std::endl;
                        return 0;
                    }
                    std::swap(val[problem[i] + j], val[k]);
                }
            }
        }
    }
    
    std::cout << -1;
}