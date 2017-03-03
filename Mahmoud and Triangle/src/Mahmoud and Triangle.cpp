#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int val[maxn];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    sort(val, val + n);

    for(int i = 0; i + 2 < n; i++){
    	if(val[i + 2] < val[i] + val[i + 1]){
    		cout << "YES" << endl;
    		return 0;
    	}
    }

    cout << "NO";
}
