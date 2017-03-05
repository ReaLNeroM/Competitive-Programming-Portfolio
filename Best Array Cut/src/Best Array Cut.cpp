#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int sum[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> val[i];
        sum[i] = sum[i - 1] + val[i];
    }

    int maxx = 1e9;
    for(int i = 2; i < n; i++){
        maxx = min(maxx, abs(sum[i] - (sum[n] - sum[i])));
    }

    cout << maxx;
}
