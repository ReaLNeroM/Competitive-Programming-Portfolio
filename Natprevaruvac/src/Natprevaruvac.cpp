#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll maxn = 30;
const ll maxp = 100;
const ll maxo = 10;
 
ll n;
ll o;
string str[maxo];
ll needed;
ll dp[maxn][1 << maxo][maxp];
ll trans[maxp][26];
map<string, ll> m;
map<ll, string> d;
map<ll, ll> done;
 
ll dfs(ll pos, ll fill, ll p){
    if(dp[pos][fill][p] == -1){
        ll &res = dp[pos][fill][p];
 
        res = 0;
        if(pos == n and fill == needed){
            res = 1;
        } else if(pos == n){
            res = 0;
        } else {
            for(char i = 'a'; i <= 'z'; i++){
                ll next = trans[p][i - 'a'];
 
                res += dfs(pos + 1, fill | done[next], next);
            }
        }
    }
 
    return dp[pos][fill][p];
}
 
void act(ll pos, ll fill, ll p, string also){
    if(pos == n and fill == needed){
        cout << also << endl;
    } else if(pos == n){
        return;
    } else {
        for(char i = 'a'; i <= 'z'; i++){
            ll next = trans[p][i - 'a'];
 
            if(dp[pos + 1][fill | done[next]][next] != 0){
                act(pos + 1, fill | done[next], next, also + i);
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
 
    cin >> n;
 
    cin >> o;
    needed = (1 << o) - 1;
 
    for(ll i = 0; i < maxn; i++){
        for(ll j = 0; j < (1 << maxo); j++){
            for(ll k = 0; k < maxp; k++){
                dp[i][j][k] = -1;
            }
        }
    }
 
    ll neww = 1;
    for(ll i = 0; i < o; i++){
        cin >> str[i];
 
        string x = "";
        for(ll j = 0; j < str[i].size(); j++){
            x += str[i][j];
            m[x] = neww;
            d[neww] = x;
            neww++;
        }
    }
    m[""] = 0;
    d[0] = "";
    for(ll i = 0; i < maxp; i++){
        if(d.find(i) != d.end()){
            for(ll j = 0; j < o; j++){
                if(d[i].size() >= str[j].size() and d[i].find(str[j]) != string::npos){
                    done[i] |= 1 << j;
                }
            }
        }
        char c = 'a';
        for(ll j = 0; j < 26; j++){
            string tryy = d[i] + c;
            while(m.find(tryy) == m.end()){
                tryy.erase(tryy.begin());
            }
 
            trans[i][j] = m[tryy];
 
            c++;
        }
    }
 
 
    cout << dfs(0, 0, 0) << endl;
 
    if(dfs(0, 0, 0) <= 30){
        act(0, 0, 0, "");
    }
}
