#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
int tezm[maxn];
int tezz[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int maski;
    cin >> maski;

    for(int i = 0; i < maski; i++){
        cin >> tezm[i];
    }
    sort(tezm, tezm + maski);

    int zenski;
    cin >> zenski;

    for(int i = 0; i < zenski; i++){
        cin >> tezz[i];
    }
    sort(tezz, tezz + zenski);

    int razlika, k;
    cin >> razlika >> k;

    int res = 0;
    for(int i = k - 1; i < zenski; i++){
        int l = 0, r = maski - 1;

        int najtezok = -1;
        while(l <= r){
            int mid = (l + r) / 2;

            if(tezm[mid] - tezz[i - (k - 1)] > razlika){
                r = mid - 1;
            } else {
                l = mid + 1;
                najtezok = mid;
            }
        }

        int najlek = 0;
        l = 0, r = maski - 1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(tezz[i] - tezm[mid] > razlika){
                l = mid + 1;
            } else {
                r = mid - 1;
                najlek = mid;
            }
        }

        res = max(res, max(0, najtezok - najlek + 1));
    }
    cout << res;
}
