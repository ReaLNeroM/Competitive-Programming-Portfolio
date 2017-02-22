#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct dsu {
    dsu* parent = this;
    int ind;
    int rank = 0;

    dsu* head(){
        if(parent != parent->parent){
            parent = parent->head();
        }

        return parent;
    }
    void merge(dsu* second){
        dsu* first = head();
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

const int maxn = 1e3;
char mat[maxn][maxn];
dsu dd[maxn][maxn];

vector<pair<int, int>> c;
vector<int> comp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int y, x;
    cin >> y >> x;

    int w;
    cin >> w;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'C'){
                c.push_back({i, j});
            }
        }
    }

    const int ay[] = {1, -1, 0, 0};
    const int ax[] = {0, 0, 1, -1};

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            for(int k = 0; k < 4; k++){
                int ni = i + ay[k];
                int nj = j + ax[k];

                if(0 <= ni and ni < y and 0 <= nj and nj < x and mat[ni][nj] != '#'){
                    dd[i][j].merge(&dd[ni][nj]);
                }
            }
        }
    }

    for(int i = 0; i < c.size(); i++){
        comp.push_back(dd[c[i].first][c[i].second].head()->ind);
    }


    int best = 0;
    int besty = 0, bestx = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(mat[i][j] != 'C' and mat[i][j] != '#'){
                int found = 0;

                int my_comp = dd[i][j].head()->ind;

                for(int k = 0; k < c.size(); k++){
                    if(my_comp == comp[k] and abs(i - c[k].first) + abs(j - c[k].second) <= w){
                        found++;
                    }
                }

                if(found > best){
                    best = found;
                    besty = i;
                    bestx = j;
                }
            }
        }
    }

    cout << besty + 1 << ' ' << bestx + 1 << endl;
}
