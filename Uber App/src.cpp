#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

const int maxn = 155;
const int most_dist = 200005;
static int matrix[maxn][maxn];
static int boolean[maxn][maxn];
static bool used[maxn];
static int pair[maxn];

class UberApp {
    int customers, rides;

    int get_dist(int a, int b, int c, int d){
        return std::abs(c - a) + std::abs(d - b);
    }

    bool replace(int x){
        if(used[x]){
            return false;
        }
        used[x] = true;

        for(int i = 0; i < rides; i++){
            if(boolean[x][i] and (pair[i] == -1 or replace(pair[i]))){
                pair[i] = x;
                return true;
            }
        }

        return false;
    }

    int bipartite(){
        std::fill(pair, pair + maxn, -1);

        int get = 0;
        for(int i = 0; i < customers; i++){
            std::fill(used, used + maxn, false);

            //try to include i
            if(replace(i)){
                get++;
            }
        }

        return get;
    }

    bool attempt(int dist){
        for(int i = 0; i < customers; i++){
            for(int j = 0; j < rides; j++){
                boolean[i][j] = (matrix[i][j] <= dist);
            }
        }

        int get_res = bipartite();

        if(get_res == customers){
            return true;
        }

        return false;
    }
public:
    int findRides(std::vector<int> px, std::vector<int> py, std::vector<int> rx, std::vector<int> ry){
        customers = px.size();
        rides = rx.size();

        for(int i = 0; i < customers; i++){
            for(int j = 0; j < rides; j++){
                matrix[i][j] = get_dist(px[i], py[i], rx[j], ry[j]);
            }
        }

        int l = 0, r = most_dist;
        int best = most_dist;
        while(l <= r){
            int mid = (l + r) / 2;
            if(attempt(mid)){
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return best;
    }
};