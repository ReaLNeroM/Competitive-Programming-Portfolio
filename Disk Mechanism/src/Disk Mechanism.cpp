#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int sr[maxn], br[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> sr[i] >> br[i];
    }
    
    int l = sr[0], r = br[0];
    for(int i = 1; i < n; i++){
        int curr_r = (val[i] - val[i - 1]) - l, curr_l = (val[i] - val[i - 1]) - r;
        
        curr_l = max(curr_l, sr[i]);
        curr_r = min(curr_r, br[i]);
        
        l = curr_l;
        r = curr_r;
    }
    
    cout << max(0, r - l + 1);
}