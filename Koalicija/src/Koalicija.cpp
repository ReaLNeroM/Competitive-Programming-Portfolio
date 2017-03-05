#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string add(string a, string b){
    string res = "";
    int carry = 0;
    for(int i = 0; i < a.size() or i < b.size() or carry; i++){
        res.insert(res.begin(), '0');
        if(i < a.size()){
            res[0] += a[a.size() - 1 - i] - '0';
        }
        if(i < b.size()){
            res[0] += b[b.size() - 1 - i] - '0';
        }
        if(carry){
            res[0] += 1;
        }

        if(res[0] > '9'){
            res[0] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    while(!res.empty() and res[0] == '0'){
        res.erase(res.begin());
    }

    return res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    string s = "0";
    string s2 = "2";

    for(int i = 1; i <= n; i++){
        s = add(s, s2);
        s2 = add(s2, s2);
    }

    cout << s;
}
