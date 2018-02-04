#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
const int maxd = 6;
int val[maxn][maxd];
int summed[maxn];
int curr_array[maxd];
int res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, d;
    std::cin >> n >> d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            std::cin >> val[i][j];
        }
    }

    curr_array[0] = 1;
    for(int i = 0; i < (1 << (d - 1)); i++){
        for(int j = 1, bit = 1; j < d; j++, bit *= 2){
            if(bit & i){
                curr_array[j] = -1;
            } else {
                curr_array[j] = 1;
            }
        }

        for(int j = 0; j < n; j++){
            summed[j] = 0;
            for(int k = 0; k < d; k++){
                summed[j] += curr_array[k] * val[j][k];
            }

            // std::cout << summed[j] << ' ';
        }
        // std::cout << '\n';

        std::sort(summed, summed + n);

        res = std::max(res, std::abs(summed[n - 1] - summed[0]));
    }

    std::cout << res << '\n';
}