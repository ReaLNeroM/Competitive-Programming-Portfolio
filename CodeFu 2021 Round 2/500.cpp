// https://codefu.mk/codefu2021-round2.html?subpage=problem&problemid=3276

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

typedef long long ll;
using namespace std;
const ll maxn = 2e5 + 1e2;
ll val[maxn];
struct trie {
    int count = 0;
    trie *l = NULL;
    trie *r = NULL;
};

class XorChallenge {
public:
    trie root;
    void insert_num(ll v){
        trie *currTrie = &root;
        ll currBit = 1 << (30 - 1);
        for(int i = 0; i < 30; i++){
            if(v & currBit){
                // make right
                if(!currTrie->r){
                    currTrie->r = new trie;
                    currTrie->r->count = 0;
                }

                currTrie->r->count++;
                currTrie = currTrie->r;
            } else {
                // make left
                if(!currTrie->l){
                    currTrie->l = new trie;
                    currTrie->l->count = 0;
                }

                currTrie->l->count++;
                currTrie = currTrie->l;
            }
            currBit /= 2;
        }
    }
    string solveChallenge(vector<int> G, int N, int Q){
        root.count = 0;
        ll x = G[3];
        ll mod = G[2];
        ll a = G[0];
        ll b = G[1];
        for(ll i = 0; i < N; i++){
            x = (a * x + b) % mod;
            val[i] = x;
            insert_num(x);
        }
        ll currS = N;
        ll res = 0;
        for(ll i = 1; i <= Q; i++){
            if(i % 2 == 1){
                x = (a * x + b) % mod;
                val[currS++] = x;
                insert_num(x);
            } else {
                x = (a * x + b) % mod;
                ll g1 = x;
                x = (a * x + b) % mod;
                ll k = x % currS;

                ll rep = k;

                ll built = 0;
                ll currBit = (1 << (30 - 1));
                trie *currTrie = &root;
                for(int j = 0; j < 30; j++){
                    trie *l = currTrie->l;
                    trie *r = currTrie->r;
                    if(g1 & currBit){
                        std::swap(l, r);
                    }
                    if(!l){
                        built |= currBit;
                        currTrie = r;
                    } else if(l->count <= k){
                        k -= l->count;
                        built |= currBit;
                        currTrie = r;
                    } else {
                        currTrie = l;
                    }
                    currBit /= 2;
                }

                res += built;
            }
        }

        return to_string(res);
    }
};
