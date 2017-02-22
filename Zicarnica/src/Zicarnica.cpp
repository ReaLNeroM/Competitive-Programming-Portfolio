#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int taken = 0;
    int left = 0;
    for(int i = 0; i < n; i++){
        cin >> val[i];

        if(val[i] > left){
            taken++;
            left = m;
        }
        left -= val[i];
    }

    cout << taken;
}
