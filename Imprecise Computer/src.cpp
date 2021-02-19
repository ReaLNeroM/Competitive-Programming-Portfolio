// https://codeforces.com/gym/102920/problem/E

#include <bits/stdc++.h>

typedef long long ll;

enum s {
    started1,
    none
};

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    bool good = true;
    s d = none;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;

        if(x == 2 and d == none){
            good = false;
        } else if(x == 1 and d == started1){
            d = none;
        } else if(x == 1){
            d = started1;
        }
    }

    good &= (d == none);
    if(good){
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    std::cout << '\n';
}