#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e3;
int special[maxn];
int x[maxn];
int y[maxn];
int closest[maxn];
int res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;
    
    for(int i = 0; i < n; i++){
        cin >> special[i] >> x[i] >> y[i];
        closest[i] = 1e9;
    }

    for(int i = 0; i < n; i++){
        if(special[i]){
            for(int j = 0; j < n; j++){
                closest[j] = min(closest[j], abs(x[i] - x[j]) + abs(y[i] - y[j]));
            }
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        res = 1e9;
        int a, b;
        cin >> a >> b;
        a--, b--;

        res = abs(x[a] - x[b]) + abs(y[a] - y[b]);
        if(special[a] and special[b]){
            res = min(res,            +            + t);
        } else if(special[a]){
            res = min(res,            + closest[b] + t);
        } else if(special[b]){
            res = min(res, closest[a] +            + t);
        } else {
            res = min(res, closest[a] + closest[b] + t);
        }
        cout << res << '\n';
    }
}