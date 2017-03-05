#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    ostringstream ostr;
    for(int i = n; i <= m; i++){
        ostr << i;
    }

    int k;
    cin >> k;

    cout << ostr.str().size() - ostr.str().size() / k;
}
