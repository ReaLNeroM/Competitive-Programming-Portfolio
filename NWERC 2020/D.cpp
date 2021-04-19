// https://codeforces.com/gym/103049/problem/D

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e6 + 1e2;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
    if (a == b) { assert(r1 != r2); return false; }
    P vec = b - a;
    double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
           p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if (sum*sum < d2 || dif*dif > d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
    *out = {mid + per, mid - per};
    return true;
}

ll q(ll a, ll b){
    cout << a << ' ' << b << endl;
    ll r;
    cin >> r;
    return r;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    ll n;
    std::cin >> n;

    std::srand(std::time(0));

    for(ll balls = 0; balls < n; balls++){
        bool good = false;

        std::vector<std::vector<ll>> queries;
        ll randx, randy, dist;
        for(int i = 0; i < 20; i++){
            randx = std::rand() % 1000001;
            randy = std::rand() % 1000001;
            dist = q(randx, randy);
            if(dist == 0){
                good = true;
                break;
            }
            queries.push_back({randx, randy, dist});
        }

        if(good){
            continue;
        }

        std::vector<std::pair<ll, ll>> candidates;
        for(int i = 0; i < 20; i++){
            for(int j = i + 1; j < 20; j++){
                for(int k = j + 1; k < 20; k++){
                    std::pair<P, P> res;
                    if(circleInter(
                        P(queries[i][0], queries[i][1]),
                        P(queries[j][0], queries[j][1]),
                        std::sqrt(queries[i][2]), std::sqrt(queries[j][2]), &res)){

                        P a = res.first;
                        for(ll l = a.x - 1; l <= a.x + 1; l++){
                            for(ll m = a.y - 1; m <= a.y + 1; m++){
                                if((l - queries[i][0]) * (l - queries[i][0]) + (m - queries[i][1]) * (m - queries[i][1]) == queries[i][2]){
                                    if((l - queries[j][0]) * (l - queries[j][0]) + (m - queries[j][1]) * (m - queries[j][1]) == queries[j][2]){
                                        if((l - queries[k][0]) * (l - queries[k][0]) + (m - queries[k][1]) * (m - queries[k][1]) == queries[k][2]){
                                            candidates.push_back({l, m});
                                        }
                                    }
                                }
                            }
                        }
                        a = res.second;
                        for(ll l = a.x - 1; l <= a.x + 1; l++){
                            for(ll m = a.y - 1; m <= a.y + 1; m++){
                                if((l - queries[i][0]) * (l - queries[i][0]) + (m - queries[i][1]) * (m - queries[i][1]) == queries[i][2]){
                                    if((l - queries[j][0]) * (l - queries[j][0]) + (m - queries[j][1]) * (m - queries[j][1]) == queries[j][2]){
                                        if((l - queries[k][0]) * (l - queries[k][0]) + (m - queries[k][1]) * (m - queries[k][1]) == queries[k][2]){
                                            candidates.push_back({l, m});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for(auto i : candidates){
            if(q(i.first, i.second) == 0){
                break;
            }
        }
    }
}
