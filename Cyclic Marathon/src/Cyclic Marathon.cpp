#include <iostream>
#include <queue>
#include <map>

struct push {
    double t;
    int ind1, ind2;
};

static std::pair<int, int> p[500001];
static push mins[1000001];
int n, l;

double time(int ind1, int ind2){
    double t = p[ind2].first - p[ind1].first;

    if(p[ind1].first > p[ind2].first){
        t += l;
    }

    t /= (double) (p[ind1].second - p[ind2].second);

    return t;
}

std::multimap<int, int> m;

void update(int i){
    std::multimap<int, int>::iterator ite = m.lower_bound(p[i].first);

    ite++;
    if(ite == m.end()){
        ite = m.begin();
    }

    int ind1 = i, ind2 = ite->second;

    push c;
    c.ind1 = ind1;
    c.ind2 = ind2;

    if(p[ind1].second > p[ind2].second){ //if ind1 == ind2, then v1 and v2 are equal
        c.t = time(ind1, ind2);
    } else {
    	c.t = 100000000;
    }

   	mins[n + i] = c;

   	for(int pos = (n + i) / 2; pos > 0; pos /= 2){
   		if(mins[2 * pos + 1].t < mins[2 * pos].t){
   			mins[pos] = mins[2 * pos + 1];
   		} else {
   			mins[pos] = mins[2 * pos];
   		}
   	}
}

int main() {
    std::ios::sync_with_stdio(false);

    std::cin >> n >> l;

    l *= 100;

    bool used[n];

    int maxspeed = 0;
    int peopleatmax = 0;

    for(int i = 0; i < 2 * n; i++){
    	mins[i].t = 100000000;
    }

    for(int i = 0; i < n; i++){
        double s;
        std::cin >> p[i].first >> s;
        p[i].first *= 100;
        p[i].second = s * 100 + 0.00001;
        m.insert(std::make_pair(p[i].first, i));

        if(p[i].second > maxspeed){
            maxspeed = p[i].second;
            peopleatmax = 1;
        } else if(p[i].second == maxspeed){
            peopleatmax++;
        }

        used[i] = false;
    }

    for(int i = 0; i < n; i++){
        update(i);
    }

    for(int i = 0; i < n - peopleatmax; i++){
    	push mval = mins[1];

        if(!used[mval.ind1] and !used[mval.ind2]){
            std::cout << mval.ind2 + 1 << std::endl;

            std::multimap<int, int>::iterator ite = m.find(p[mval.ind2].first);

            while(ite->second != mval.ind2){
                ite++;
            }
            m.erase(ite);

            used[mval.ind2] = true;
            mins[n + mval.ind2].t = 100000000;
    	   	for(int pos = (n + mins[1].ind2) / 2; pos > 0; pos /= 2){
    	   		if(mins[2 * pos + 1].t < mins[2 * pos].t){
    	   			mins[pos] = mins[2 * pos + 1];
    	   		} else {
    	   			mins[pos] = mins[2 * pos];
    	   		}
    	   	}

            update(mval.ind1);
        }
    }

    std::cout << "Winner(s): ";
    for(int i = 0; i < n; i++){
        if(!used[i]){
            std::cout << i + 1 << ' ';
        }
    }

    return 0;
}
