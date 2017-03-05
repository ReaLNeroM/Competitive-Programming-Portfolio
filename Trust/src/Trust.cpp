#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 25;
const int maxt = 105;
int tip[maxn][maxn];
int cost[maxn][maxn];
int used[maxn][maxt];
int dp[(1 << 20)];
vector<pair<int, int> > used_by[maxn][maxt];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int komp, grad;
    cin >> komp >> grad;

    for(int i = 0; i < komp; i++){
        for(int j = 0; j < grad; j++){
            cin >> tip[i][j];
            used[j][tip[i][j]]++;
        }
    }
    for(int i = 0; i < komp; i++){
        for(int j = 0; j < grad; j++){
            cin >> cost[i][j];
            used_by[j][tip[i][j]].push_back(make_pair(i, cost[i][j]));
        }
    }

    for(int i = (1 << komp) - 1; i >= 0; i--){
        vector<int> v;
        int res = 0;
        for(int j = 0, bit = 1; j < komp; j++, bit *= 2){
            if((bit & i) == 0){
                res = dp[i + bit];
                int best = 1e9;
                for(int l = 0; l < grad; l++){
                    best = min(best, cost[j][l]);
                }
                res += best;
                break;
            }
        }

        dp[i] = res;
    }

    for(int i = 0; i < grad; i++){
        for(int j = 1; j <= 100; j++){
            if(used_by[i][j].size()){
                int full_bit = 0;
                int full_sum = 0;
                int biggest_seen = 0;
                for(int k = 0; k < used_by[i][j].size(); k++){
                    full_bit |= (1 << used_by[i][j][k].first);
                    full_sum += used_by[i][j][k].second;
                    biggest_seen = max(biggest_seen, used_by[i][j][k].second);
                }

                full_sum -= biggest_seen;
                ll temp;
                for(int l = 0; l < (1 << komp);){
                    dp[l] = min(dp[l], dp[l | full_bit] + full_sum);
                    l++;
                    temp = l & full_bit;
                    while(l < (1 << komp) and temp == full_bit){
                        l += temp & -temp;
                        temp = l & full_bit;
                    }
                }
            }
        }
    }

    cout << dp[0];
}
