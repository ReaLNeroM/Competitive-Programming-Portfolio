#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int n;
std::string input;
char* left[maxn], *right[maxn];
ll res = 0;

bool good(int steps){
    for(int i = 0; i < n; i++){
        if(i == 0){
            left[i] = 0;
        } else {
            left[i] = &input[i - 1];
        }
        if(i == n - 1){
            right[i] = 0;
        } else {
            right[i] = &input[i + 1];
        }
    }   
}

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> input;
    n = input.size();

    int l = 0, r = input.size();
    while(l <= r){
        int mid = (l + r) / 2;

        if(good(mid)){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::cout << res << '\n';
}