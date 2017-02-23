#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);

    ll kids;
    std::cin >> kids;

    ll atdent[kids], atquit[kids], confidence[kids];
    for(ll i = 0; i < kids; i++){
        std::cin >> atdent[i] >> atquit[i] >> confidence[i];
    }

    ll modifier = 0;
    std::vector<ll> kidsatdentist;
    for(ll i = 0; i < kids; i++){
        confidence[i] -= modifier;

        for(ll j = 0; j < kidsatdentist.size(); j++){
            confidence[i] -= atdent[kidsatdentist[j]];

            if(atdent[kidsatdentist[j]] > 0){
                atdent[kidsatdentist[j]]--;
            }
        }

        if(confidence[i] >= 0){
            kidsatdentist.push_back(i);
        } else {
            modifier += atquit[i];
        }
    }

    std::cout << kidsatdentist.size() << std::endl;
    for(ll i = 0; i < kidsatdentist.size(); i++){
        std::cout << kidsatdentist[i] + 1 << ' ';
    }
    return 0;
}
