#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 55;
const ll INF = 1000000000000000010;

bool a[4][maxn];
int s[4];
string orig[4];

int occurrences[maxn];

ll my_gcd(ll a, ll b){
    while(b != 0){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int n, q;
int dpforward[maxn][maxn][maxn];
int dpbackward[maxn][maxn][maxn];

ll dpfuncbackward(ll pos, ll c, ll d){
    if(pos < 0 or c < 0 or d < 0){
        return 0;
    }

    int& ans = dpbackward[pos][c][d];
    if(ans != -1){
        return ans;
    }

    ans = 0;
    if(pos == 0){
        if(c == 0 and d == 0){
            ans = 1;
        }
        return ans;
    }

    // set to true
    if((!a[1][pos] or c > 0) and (!a[2][pos] or d > 0)){
        ans += dpfuncbackward(pos - 1, c - a[1][pos], d - a[2][pos]);
    }

    // set to false
    if((a[1][pos] or c > 0) and (a[2][pos] or d > 0)){
        ans += dpfuncbackward(pos - 1, c - (!a[1][pos]), d - (!a[2][pos]));
    }

    return ans;
}

ll dpfuncforward(ll pos, ll c, ll d){
    if(pos < 0 or c < 0 or d < 0){
        return 0;
    }

    int& ans = dpforward[pos][c][d];
    if(ans != -1){
        return ans;
    }

    ans = 0;
    if(pos == q + 1){
        if(c == 0 and d == 0){
            ans = 1;
        }
        return ans;
    }

    // set to true
    if((!a[1][pos] or c > 0) and (!a[2][pos] or d > 0)){
        ans += dpfuncforward(pos + 1, c - a[1][pos], d - a[2][pos]);
    }

    // set to false
    if((a[1][pos] or c > 0) and (a[2][pos] or d > 0)){
        ans += dpfuncforward(pos + 1, c - (!a[1][pos]), d - (!a[2][pos]));
    }

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        std::cin >> n >> q;

        memset(occurrences, 0, sizeof(occurrences));
        memset(dpforward, -1, sizeof(dpforward));
        memset(dpbackward, -1, sizeof(dpbackward));

        for(int i = 1; i <= n; i++){
            std::cin >> orig[i] >> s[i];
            for(int j = 1; j <= q; j++){
                a[i][j] = (orig[i][j - 1] == 'T');
            }
        }

        if(n == 1){
            if(s[1] > q - s[1]){
                cout << orig[1] << ' ' << s[1] << "/1" << '\n';
            } else {
                for(int i = 0; i < q; i++){
                    if(orig[1][i] == 'T'){
                        cout << 'F';
                    } else {
                        cout << 'T';
                    }
                }
                cout << ' ' << q - s[1] << "/1" << '\n';
            }
            continue;
        } else if(n == 2){
            long long total = dpfuncbackward(q, s[1], s[2]);
            total = dpfuncforward(1, s[1], s[2]);

            if((!a[1][1] or s[1] > 0) and (!a[2][1] or s[2] > 0)){
                occurrences[1] = dpfuncforward(2, s[1] - a[1][1], s[2] - a[2][1]);
            }
            if((!a[1][q] or s[1] > 0) and (!a[2][q] or s[2] > 0)){
                occurrences[q] = dpfuncbackward(q - 1, s[1] - a[1][q], s[2] - a[2][q]);
            }
            for(int i = 2; i < q; i++){
                int c = s[1] - a[1][i];
                int d = s[2] - a[2][i];
                for(int j = 0; j <= c; j++){
                    for(int k = 0; k <= d; k++){
                        occurrences[i] += dpfuncforward(i + 1, j, k) * dpfuncbackward(i - 1, c - j, d - k);
                    }
                }
            }

            string best = "";
            ll a = 0, b = total;
            for(int i = 1; i <= q; i++){
                if(occurrences[i] > total - occurrences[i]){
                    best += 'T';
                    a += occurrences[i];
                } else {
                    best += 'F';
                    a += total - occurrences[i];
                }
            }

            ll gcd = my_gcd(a, b);
            a /= gcd;
            b /= gcd;

            cout << best << ' ' << a << '/' << b << '\n';
        }
    }
}