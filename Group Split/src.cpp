#include <bits/stdc++.h>

typedef long long ll;

ll res = 1;

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 2; i * i <= n; i++){
        int times = 1;
        while(n % i == 0){
            n /= i;
            times++;
        }
        res *= times;
    }

    if(n > 1){
        res *= 2;
    }

    std::cout << res - 1;
}