#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

bool a[3][maxn];
int s[3];
string orig[3];

int occurrences[maxn];

ll my_gcd(ll a, ll b){
    while(b != 0){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n, q;
        std::cin >> n >> q;

        memset(occurrences, 0, sizeof(occurrences));

        for(int i = 0; i < n; i++){
            std::cin >> orig[i] >> s[i];
            for(int j = 0; j < q; j++){
                a[i][j] = (orig[i][j] == 'T');
            }
        }

        int total = 0;
        cout << total << '\n';
        continue;

        for(int bitset = 0; bitset < (1 << q); bitset++){
            bool good = true;
            for(int i = 0; i < n; i++){
                int hisscore = 0;
                for(int j = 0; j < q; j++){
                    int official_answer = (bitset & (1 << j)) != 0;
                    int his_answer = a[i][j];
                    if(official_answer == his_answer){
                        hisscore++;
                    }
                }
                if(hisscore != s[i]){
                    good = false;
                    break;
                }
            }
            if(good){
                for(int j = 0; j < q; j++){
                    int official_answer = bitset & (1 << j);
                    if(official_answer){
                        occurrences[j]++;
                    }
                }
                total++;
            }
        }

        string best = "";
        ll a = 0, b = total;
        for(int i = 0; i < q; i++){
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

        cout << best << ' ' << a << '/' << b;
        //TODO

        std::cout << '\n';
    }
}