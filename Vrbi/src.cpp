#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
bool cmp(pair<int, int> f, pair<int, int> s){
    return f.second > s.second;
}
 
const int maxn = 100;
int n, t, d;
pair<int, int> h[maxn];
 
int dp[maxn][maxn];
 
int findx(int pos, int left){
    if(dp[pos][left] == -1){
        if(pos == n){
            dp[pos][left] = 0;
        } else if(left > 0){
            dp[pos][left] = h[pos].first + h[pos].second * d + findx(pos + 1, left);
            dp[pos][left] = min(dp[pos][left], findx(pos + 1, left - 1) + (d - left) * h[pos].second);
        } else {
            dp[pos][left] = h[pos].first + h[pos].second * d + findx(pos + 1, left);
        }
    }
 
    return dp[pos][left];
}
 
int main(){
    ios::sync_with_stdio(false);
 
    cin >> n >> t;
 
    for(int i = 0; i < n; i++){
        cin >> h[i].first >> h[i].second;
    }
    sort(h, h + n, cmp);
 
    for(d = 1; d <= n; d++){
        for(int j = 0; j < maxn; j++){
            for(int k = 0; k < maxn; k++){
                dp[j][k] = -1;
            }
        }
 
        if(findx(0, d) < t){
            cout << d << '\n';
            break;
        }
    }
    return 0;
}