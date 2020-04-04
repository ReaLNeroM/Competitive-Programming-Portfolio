#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int n;
int mat[maxn][maxn];
bool binary_mat[maxn][maxn];

bool good(int percentage){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            binary_mat[i][j] = (mat[i][j] >= percentage);
        }
    }

    bool row_with_all_ones = false;

    for(int i = 0; i < n; i++){
        bool found_zero = false;
        for(int j = 0; j < n; j++){
            if(binary_mat[i][j] == 0){
                found_zero = true;
            }
        }

        if(!found_zero){
            row_with_all_ones = true;
        }
    }

    return row_with_all_ones;
}

int main(){
    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> mat[i][j];
        }
    }

    int l = 1, r = 100;
    int best = 0;
    while(l <= r){
        int mid = (l + r) / 2;

        if(good(mid)){
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    std::cout << best << '\n';
}