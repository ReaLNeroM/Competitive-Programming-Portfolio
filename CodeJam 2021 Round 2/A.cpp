#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;
using namespace std;

int val[maxn];
int n;

void sort_to(vector<int> v){
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(v[i] == j and i != j){
                cout << "S " << i + 1 << " " << j + 1 << '\n';
                swap(v[i], v[j]);
            }
        }
    }
    cout.flush();
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases >> n;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        for(int i = 1; i <= n - 1; i++){
            cout << "M " << i << " " << n << endl;
            int r;
            cin >> r;
            if(r == i){
                continue;
            }
            if(i < r){
                cout << "S " << i << " " << r << endl;
            } else {
                cout << "S " << r << " " << i << endl;
            }
            cin >> r;
        }
        cout << "D" << endl;
        int r;
        cin >> r;
        if(r == -1){
            return -1;
        }
    }
}