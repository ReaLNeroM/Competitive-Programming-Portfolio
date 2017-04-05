#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e2 + 1e2;
const ll maxcircle = 1e3;
ll n, percent;
pair<ll, ll> p[maxn];
pair<double, double> circ[maxcircle];
pair<double, double> new_circ[maxcircle];
vector<vector<pair<ll, ll>>> tri;
double fir, sec;
double radius;
double eps = 0.000000001;

ll convex(ll a, ll b, ll c){
	return (p[b].first - p[a].first) * (p[c].second - p[a].second) - (p[b].second - p[a].second) * (p[c].first - p[a].first);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	double angle_a = atan2((double) a.first - fir, (double) a.second - sec);
	double angle_b = atan2((double) b.first - fir, (double) b.second - sec);

	return angle_a < angle_b;
}

double cross_res(pair<ll, ll> a, pair<ll, ll> b, pair<double, double> c){
	pair<double, double> a1 = {a.first, a.second};
	pair<double, double> b1 = {b.first, b.second};

	return (double) (b1.first - a1.first) * (double) (c.second - a1.second) - (double) (b1.second - a1.second) * (double) (c.first - a1.first);
}

int cross(pair<ll, ll> a, pair<ll, ll> b, pair<double, double> c){
	pair<double, double> a1 = {a.first, a.second};
	pair<double, double> b1 = {b.first, b.second};

	double res = (double) (b1.first - a1.first) * (double) (c.second - a1.second) - (double) (b1.second - a1.second) * (double) (c.first - a1.first);

	if(res < -eps){
		return -1;
	} else if(res > eps){
		return 1;
	} else {
		return 0;
	}
}

double intersect(ll pos){
	int found = 0;

	for(int i = 0; i < 3; i++){
		if(tri[pos][i].first * tri[pos][i].first + tri[pos][i].second * tri[pos][i].second <= radius * radius){
			found++;
		}
	}

	if(found == 0){
		return 0.0;
	} else if(found == 3){
		return abs(cross_res(tri[pos][0], tri[pos][1], tri[pos][2])) / 2.0;
	} else {

	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double ite = (4.0 * acos(0)) / (double) maxcircle;
	double curr_angle = 0.0;
	for(ll j = 0; j < maxcircle; j++){
		circ[j] = {sin(curr_angle), cos(curr_angle)};
		curr_angle += ite;
	}
	reverse(circ, circ + maxcircle); //so that it's counterclockwise

	while(cin >> n >> percent){
		double percent_in_double = (double) percent / 100.0;
		fir = 0.0, sec = 0.0;
		tri.clear();

		for(ll i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
			fir += p[i].first, sec += p[i].second;
		}
		fir /= (double) n, sec /= (double) n;
		fir -= eps;

		vector<ll> left;
		for(ll i = 0; i < n; i++){
			left.push_back(i);
		}

		double area2 = 0.0;
		for(ll i = 0; i < n; i++){
			area2 += p[i].first * p[(i + 1) % n].second;
			area2 -= p[i].second * p[(i + 1) % n].first;
		}

		if(area2 < eps){
			reverse(p, p + n); //this means it was given clockwise
		}

		double area = 0.0;
		for(ll i = 0; i < n; i++){
			for(ll j = 1; j < left.size(); j++){
				ll prev  = left[j - 1];
				ll curr  = left[j];
				ll nnext = left[(j + 1) % left.size()];

				if(prev != curr and curr != nnext and prev != nnext){
					if(convex(prev, curr, nnext) == 0){
						left.erase(left.begin() + j);
						break;
					} else if(convex(prev, curr, nnext) > 0){
						bool good = true;
						double midx = (double) (p[prev].first  + p[curr].first  + p[nnext].first ) / 3.0;
						double midy = (double) (p[prev].second + p[curr].second + p[nnext].second) / 3.0;

						for(ll k = 0; k < n and good; k++){
							if(k != prev and k != curr and k != nnext and
									cross(p[prev], p[curr] , {midx, midy}) == cross(p[prev], p[curr] , p[k]) and
									cross(p[curr], p[nnext], {midx, midy}) == cross(p[curr], p[nnext], p[k]) and
									cross(p[nnext], p[prev], {midx, midy}) == cross(p[nnext], p[prev], p[k])){
								good = false;
							}
						}

						if(good){
							area += ((double) -convex(prev, curr, nnext)) / 2.0;

							vector<pair<ll, ll>> v;
							v.push_back(p[prev ]);
							v.push_back(p[curr ]);
							v.push_back(p[nnext]);
							tri.push_back(v);

							left.erase(left.begin() + j);
							break;
						}
					}
				}
			}
		}

		double l = 0.001, r = 1000000.0;

		for(ll i = 0; i < 30; i++){
			double mid = (l + r) / 2.0;
			radius = mid;

			for(ll j = 0; j < maxcircle; j++){
				new_circ[j] = {circ[j].first * mid, circ[j].second * mid};
			}
			double intersect_area = 0.0;

			for(ll j = 0; j < tri.size(); j++){
				intersect_area += intersect(j);
			}

			if(intersect_area / area - eps >= percent_in_double){
				r = mid - eps;
			} else {
				l = mid + eps;
			}
		}
	}
}

