#include <iostream>

using namespace std;
typedef long long ll;

const int mod = 123456789;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int val[n + 1];
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    val[n] = 0;

    int dp[10001], sum[10001];

    dp[0] = 1;
    for(int i = 1; i <= 10000; i++){
        dp[i] = 0;
    }

    for(int i = n; i > 0; i--){
        sum[0] = dp[0];
        for(int j = 1; j <= val[i - 1]; j++){
            sum[j] = sum[j - 1] + dp[j];
            if(sum[j] >= mod){
                sum[j] -= mod;
            }
        }
        for(int j = val[i - 1] + 1; j <= 10000; j++){
            dp[j] = 0;
            sum[j] = 0;
        }

        for(int j = 0; j <= val[i - 1]; j++){
            int max = min(val[i] + j - val[i - 1], j);

            dp[j] = 0;
            if(max >= 0){
                dp[j] += sum[max];
            } else if(i == n){
                dp[j] += 1;
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= 10000; i++){
        res += dp[i];
        if(res >= mod){
            res -= mod;
        }
    }
    cout << res;
    return 0;
}
