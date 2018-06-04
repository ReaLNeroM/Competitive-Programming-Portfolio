#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

const static int maxn = 2e6 + 1e2;
static int val[maxn];
static bool used[maxn];

class FlippingCards {
public:
    int transform(std::string x){
        int bitset = 0;
        for(int i = 0; i < x.size(); i++){
            bitset *= 2;
            bitset += (x[i] == 'U');
        }

        std::vector<int> changes;
        for(int i = 1; i < x.size() - 1; i++){
            changes.push_back((1 << (i - 1)) + (1 << (i)) + (1 << (i + 1)));
        }

        int most = (1 << x.size()) - 1;
        std::fill(val, val + maxn, -1);

        std::queue<int> q;
        q.push(bitset);
        used[bitset] = true;
        val[bitset] = 0;

        while(!q.empty()){
            int fr = q.front();
            q.pop();

            for(int j = 0; j < changes.size(); j++){
                int next = fr ^ changes[j];

                if(val[next] == -1 and used[next] == false){
                    used[next] = true;
                    val[next] = val[fr] + 1;
                    q.push(next);
                }
            }
        }

        return val[0];
    }
};