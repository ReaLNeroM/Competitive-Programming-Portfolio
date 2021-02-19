#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int x[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    int w, p;
    std::cin >> w >> p;

    x[0] = 0;
    x[p + 1] = w;
    for(int i = 1; i <= p; i++){
        std::cin >> x[i];
    }
    std::set<int> s;
    for(int i = 0; i < p + 2; i++){
        for(int j = i + 1; j < p + 2; j++){
            s.insert(std::abs(x[j] - x[i]));
        }
    }

    for(int i : s){
        std::cout << i << ' ';
    }
    std::cout << '\n';
}