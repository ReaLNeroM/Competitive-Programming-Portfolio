#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e2 + 1e2;
const ll maxcircle = 1000;
ll n, percent;
pair<ll, ll> p[maxn];
vector<vector<pair<ll, ll>>> tri;
double radius;
double eps = 0.000000001;

ll convex(ll a, ll b, ll c){
	return (p[b].first - p[a].first) * (p[c].second - p[a].second) - (p[b].second - p[a].second) * (p[c].first - p[a].first);
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
	int vertices = 0, edges = 0;

	for(int i = 0; i < 3; i++){
		if(tri[pos][i].first * tri[pos][i].first + tri[pos][i].second * tri[pos][i].second <= radius * radius){
			vertices++;
		}
	}
	for(int i = 0; i < 3; i++){

	}
	double area = 0.0;

	if(vertices == 0 and edges == 0){

	} else if(vertices == 0 and edges == 1){
		//
	} else if(vertices == 0 and edges == 2){

	} else if(vertices == 0 and edges == 3){

	} else if(vertices == 1 and edges == 2){

	} else if(vertices == 1 and edges == 3){

	} else if(vertices == 2 and edges == 3){

	} else if(vertices == 3 and edges == 3){
		return cross_res(tri[pos][0], tri[pos][1], tri[pos][2]) / 2;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(cin >> n >> percent){
		double percent_in_double = percent;
		percent_in_double /= 100.0;
		tri.clear();

		for(ll i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}

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
							area += ((double) convex(prev, curr, nnext)) / 2.0;

							vector<pair<ll, ll>> v;
							v.push_back(p[curr ]);
							v.push_back(p[prev ]);
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
		double smallest = r;
		for(ll i = 0; i < 30; i++){
			double mid = (l + r) / 2.0;
			radius = mid;

			double intersect_area = 0.0;

			for(ll j = 0; j < tri.size(); j++){
				intersect_area += intersect(j);
			}

			if(intersect_area / area + eps >= percent_in_double){
				smallest = mid;
				r = mid - eps;
			} else {
				l = mid + eps;
			}
		}

		cout.precision(2);
		cout << fixed << smallest << endl;
	}
}

