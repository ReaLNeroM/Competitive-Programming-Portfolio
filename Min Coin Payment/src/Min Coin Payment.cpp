#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll res = 0;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    res += n / 50;
    n %= 50;
    res += n / 5;
    n %= 5;
    res += n;
    
    cout << res;
    
}