// https://nena20.kattis.com/problems/march6.basicbasis

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1000 + 500;
const int maxk = 500;
int v[maxn][maxk];
int g[maxn][maxk];
int lastchange[maxn];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n, q, bits;
    std::cin >> n >> q >> bits;

    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;

        for(int j = 0; j < s.size(); j++){
            int x = 0;
            if('a' <= s[j] and s[j] <= 'f'){
                x = 10;
                x += (int) (s[j] - 'a');
            } else {
                x = s[j] - '0';
            }
            for(int k = 0, bit = 1; k < 4; k++, bit *= 2){
                if(x & bit){
                    v[i][j * 4 + k] = 1;
                } else {
                    v[i][j * 4 + k] = 0;
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        std::string s;
        std::cin >> s;

        lastchange[i] = -1;

        for(int j = 0; j < s.size(); j++){
            int x = 0;
            if('a' <= s[j] and s[j] <= 'f'){
                x = 10;
                x += (s[j] - 'a');
            } else {
                x = s[j] - '0';
            }
            for(int k = 0, bit = 1; k < 4; k++, bit *= 2){
                if((x & bit)){
                    g[i][j * 4 + k] = 1;
                } else {
                    g[i][j * 4 + k] = 0;
                }
            }
        }
    }

    bits *= 4;

    int specialcase = -1;

    for(int i = 0; i < n; i++){
        int mybit = -1;

        for(int j = 0; j < bits; j++){
            if(v[i][j]){
                mybit = j;
                break;
            }
        }

        if(mybit == -1 and specialcase == -1){
            specialcase = i + 1;
            continue;
        }

        for(int j = i + 1; j < n; j++){
            if(v[j][mybit]){
                for(int l = 0; l < bits; l++){
                    v[j][l] ^= v[i][l];
                }
            }
        }

        // see what is new in query
        for(int j = 0; j < q; j++){
            if(g[j][mybit]){
                for(int l = 0; l < bits; l++){
                    g[j][l] ^= v[i][l];
                }
                lastchange[j] = i;
            }
        }
    }

    for(int i = 0; i < q; i++){
        bool good = true;
        for(int j = 0; j < bits; j++){
            if(g[i][j]){
                good = false;
                break;
            }
        }
        if(good and lastchange[i] == -1){
            cout << specialcase << '\n';
        } else if(good and lastchange[i] != -1){
            cout << lastchange[i] + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
