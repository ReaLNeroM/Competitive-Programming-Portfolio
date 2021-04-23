// https://codefu.mk/codefu2021-round1.html?subpage=problem&problemid=3214

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
// #include <iostream>

typedef long long ll;
using namespace std;

struct DSU {
    DSU* parent = this;
    int ind;
    int rank = 0;

    DSU* head(){
        if(parent != parent->parent){
            parent = parent->head();
        }

        return parent;
    }
    void merge(DSU* second){
        DSU* first = head();
        second = second->head();

        if(first->rank > second->rank){
            second->parent = first;
        } else if(first->rank < second->rank){
            first->parent = second;
        } else {
            second->parent = first;
            first->rank++;
        }
    }
};

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

class IntergalacticCake {
public:
    int getSlices(int N, int M, vector<int> hCuts, vector<int> vCuts){
        for(int i = 0; i < hCuts.size(); i++){
            hCuts[i] += N;
        }
        for(int i = 0; i < vCuts.size(); i++){
            vCuts[i] += N;
        }
        int f = 2 * N;
        DSU comp[f][f];
        int comps = f * f;
        for(int i = 0; i < f; i++){
            for(int j = 0; j < f; j++){
                comp[i][j].ind = i * f + j;
                if((i < N and std::abs(i - N) <= M) or std::abs(i - N) < M){
                    if((j < N and std::abs(j - N) <= M) or std::abs(j - N) < M){
                        comp[i][j].ind = -2;
                        // std::cout << "#" << i << ' ' << j << '\n';
                        comps--;
                    }
                }
            }
        }

        for(int i = 0; i < f; i++){
            for(int j = 0; j < f; j++){
                if(comp[i][j].ind == -2){
                    continue;
                }
                for(int k = 0; k < 4; k++){
                    int ni = i + ay[k];
                    int nj = j + ax[k];

                    if(0 <= ni and ni < f and 0 <= nj and nj < f and comp[ni][nj].ind != -2){
                        bool h = false;
                        bool v = false;
                        if(j != nj){
                            for(int l : hCuts){
                                if(std::max(j, nj) == l){
                                    h = true;
                                    break;
                                }
                            }
                        }
                        if(i != ni){
                            for(int l : vCuts){
                                if(std::max(i, ni) == l){
                                    v = true;
                                    break;
                                }
                            }
                        }

                        if(!h and !v and comp[i][j].head() != comp[ni][nj].head()){
                            comps--;
                            comp[i][j].merge(&comp[ni][nj]);
                            // cout << i << ' ' << j << ' ' << ni << ' ' << nj << '\n';
                        }
                    }
                }
            }
        }

        return comps;
    }
};
