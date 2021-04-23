// https://codefu.mk/codefu2021-round1.html?subpage=problem&problemid=3212

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

class BlackBenduday {
public:
    string savings(vector<int> prices, vector<int> discounts, int k){
        std::vector<ll> pp;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            pp.push_back(((ll) prices[i]) * discounts[i]);
        }
        std::sort(pp.begin(), pp.end(), std::greater<ll>());

        ll best = 0;
        for(int i = 0; i < std::min(n, k); i++){
            best += pp[i];
        }

        string s = to_string(best);
        while(s.size() < 3){
            s += '0';
        }

        string f = s.substr(0, s.size() - 2) + "." + s.substr(s.size() - 2);

        return f;
    }
};
