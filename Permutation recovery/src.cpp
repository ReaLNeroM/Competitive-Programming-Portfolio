#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int n;
int p[maxn];
int next[maxn];

// Note: n may be up to 500k, but this doesn't cause a stack overflow since it's tail recursive.
int f(int l, int r, int last){
    if(l >= r){
        return last;
    }

    if(next[l] > r){
        return -maxn;
    }
    if(next[l] != -1){
        int nextvalue = f(l + 1, next[l], last);
        p[l] = nextvalue;
        return f(next[l], r, nextvalue + 1);
    } else {
        p[l] = last;
        last++;
        return f(l + 1, r, last);
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    int testcases;
    std::cin >> testcases;

    while(testcases--){
        std::cin >> n;

        for(int i = 0; i < n; i++){
            std::cin >> next[i];

            if(next[i] != -1){
                next[i]--;
            }
        }

        int ret = f(0, n, 0);

        if(ret < 0){
            std::cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < n; i++){
            std::cout << p[i] + 1 << ' ';
        }
        std::cout << '\n';
    }
}