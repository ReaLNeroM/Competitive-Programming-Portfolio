#include <iostream>

typedef long long ll;

int main() {
    ll guides, teams;
    std::cin >> guides >> teams;

    ll controls[guides][teams];
    ll sumt[teams];
    ll sumg[guides];

    for(ll j = 0; j < teams; j++){
        sumt[j] = 0;
    }

    bool used[guides];
    for (ll i = 0; i < guides; i++) {
        used[i] = false;
        for(ll j = 0; j < teams; j++){
            std::cin >> controls[i][j];
            sumt[j] += controls[i][j];
            sumg[i] += controls[i][j];
        }
    }

    ll changes = 0;
    for(ll i = 0; i < teams; i++){
        ll maxy = 0, maxx = 0;
        for(ll j = 0; j < guides; j++){
            if(!used[j]){
                for(ll k = 0; k < teams; k++){
                    if(sumg[j] - controls[j][k] < sumg[maxy] - controls[maxy][maxx]){
                        maxy = j, maxx = k;
                    }
                }
            }
        }

        used[maxy] = true;
        for(ll j = 0; j < guides; j++){
            if(j != maxy){
                changes += controls[j][maxx];
            }
			controls[j][maxx] = 0;
        }
    }

    std::cout << changes;
    return 0;
}
