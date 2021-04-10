#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

int p[maxn];
int f[maxn];

int main(){
    ios::sync_with_stdio(false);

    ll testCases;
    cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        cout << "Case #" << testcase << ": ";

        int n;
        cin >> n;

        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> p[i] >> f[i];
            sum += p[i] * f[i];
        }

        int res = 0;

        for(int j = sum - 1; j > 1; j--){
            int copyj = j;
            int sumleft = sum;
            bool good = true;
            for(int k = 0; copyj > 1 and k < n; k++){
                int times = 0;
                while(copyj % p[k] == 0){
                    copyj /= p[k];
                    times++;
                    sumleft -= p[k];
                }
                if(times > f[k]){
                    good = false;
                    break;
                }
            }

            if(good and copyj == 1 and sumleft == j){
                // yay!!
                res = j;
                break;
            }
        }

        cout << res;

        cout << '\n';
    }
}