#include <bits/stdc++.h>

const int maxn = 1000;
bool usedy[maxn];
bool usedx[maxn];

int main(){
    for(int i = 0; i < maxn; i++){
        usedy[i] = false;
        usedx[i] = false;
    }
    if(std::cin >> n){
        for(int i = 0; i < n; i++){
            int y, x;
            if(!std::cin >> y){
                return -1;
            }
            if(!std::cin >> x){
                return -1;
            }
            if(1 <= y and y <= n and 1 <= x and x <= n){
                if(usedy[y] or usedx[x]){
                    return -1;
                }
                usedy[y] = true;
                usedx[x] = true;
            } else {
                return -1;
            }
        }
    } else {
        return -1;
    }
}