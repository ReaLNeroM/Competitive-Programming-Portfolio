#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int res[maxn];

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    sort(val, val + n);
    
    for(int i = 0; i < n; i++){
        res[i] = n - 1 - i;
    }
    for(int i = 1; i + 1 < n; i += 2){
        swap(res[i], res[i + 1]);
    }
    for(int i = 0; i < n; i++){
        cout << val[res[i]] << ' ';
    }
}