/*
ID: vlade.m1
PROG: fence4
LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 205;
const double pi = acos(-1);
int py[maxn], px[maxn];
vector<pair<int, int> > res;
double angle[maxn];
const double eps = 0.0000000001;
int n;

int oy, ox;
int mult(int y1, int x1, int y2, int x2, int y3, int x3){
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool cmp(int f, int s){
	return angle[f] <= angle[s];
}

double line_dist(double angle, int index){
	int nnext = (index + 1) % n;

	double ry, rx;
	if(px[index] == px[nnext]){
		double b = px[index];

		double other_slope = tan(angle / 180.0 * pi);
		double other_b = oy - other_slope * ox;

		rx = b;
		ry = rx * other_slope + other_b;

	} else {
		double slope = (py[nnext] - py[index]);
		slope /= (double) (px[nnext] - px[index]);
		double b = py[index] - slope * px[index];

		double other_slope = tan(angle / 180.0 * pi);
		double other_b = oy - other_slope * ox;

		rx = (other_b - b) / (slope - other_slope);
		ry = rx * slope + b;
	}

	return (rx - ox) * (rx - ox) + (ry - oy) * (ry - oy);
}

int main(){
	freopen("fence4.in", "r", stdin);
	freopen("fence4.out", "w", stdout);

	cin >> n;

	cin >> oy >> ox;

	for(int i = 0; i < n; i++){
		cin >> py[i] >> px[i];
	}
	bool fence = true;

	for(int i = 0; i < n; i++){
		int found = 0;
		for(int j = 0; j < n; j++){
			int py1 = py[j], px1 = px[j];
			int py2 = py[(j + 1) % n], px2 = px[(j + 1) % n];

			if(mult(py1, px1, py[i], px[i], py2, px2) == 0){
				if(py1 > py2){
					swap(py1, py2);
				}
				if(px1 > px2){
					swap(px1, px2);
				}
				if(py1 <= py[i] and py[i] <= py2 and px1 <= px[i] and px[i] <= px2){
					found++;
				}
			}
		}
		if(found != 2){
			fence = false;
		}
	}
	for(int i = 0; i < n; i++){
		int py3 = py[i], px3 = px[i];
		int py4 = py[(i + 1) % n], px4 = px[(i + 1) % n];

		for(int j = 0; j < n; j++){
			if(i != j and (i + 1) % n != j){
				int py1 = py[j], px1 = px[j];
				int py2 = py[(j + 1) % n], px2 = px[(j + 1) % n];

				if(mult(py1, px1, py2, px2, py3, px3) != 0 and mult(py1, px1, py2, px2, py3, px3) == -mult(py1, px1, py2, px2, py4, px4)){
					if(mult(py3, px3, py4, px4, py1, px1) != 0 and mult(py3, px3, py4, px4, py1, px1) == -mult(py3, px3, py4, px4, py2, px2)){
						fence = false;
					}
				}
			}
		}
	}
	if(!fence){
		cout << "NOFENCE" << endl;
		return 0;
	}
	bool used[maxn];
	for(int i = 0; i < n; i++){
		used[i] = false;
		angle[i] = (atan2(py[i] - oy, px[i] - ox) + pi) * 180.0 / pi;
	}

	for(int x = 0; x < n; x++){
		for(double i = angle[x] - 0.000000001; i < angle[x] + 0.000000002; i += 0.000000002){
			int ind = -1;
			double dist = 1e18;

			for(int j = 0; j < n; j++){
				double new_dist = 1e20;

				double old_angle = angle[j];
				double new_angle = angle[(j + 1) % n];

				if(old_angle > new_angle){
					swap(old_angle, new_angle);
				}

				if(old_angle + 180.0 > new_angle and old_angle < i and i < new_angle){
					new_dist = line_dist(i, j);
				} else if(old_angle + 180.0 < new_angle and (old_angle > i or new_angle < i)){
					new_dist = line_dist(i, j);
				}

				if(dist > new_dist){
					dist = new_dist;
					ind = j;
				}
			}
			if(ind != -1 and !used[ind]){
				used[ind] = true;
				res.push_back({ind, (ind + 1) % n});
			}
		}
	}

	cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++){
		if(res[i].first > res[i].second){
			swap(res[i].first, res[i].second);
		}
	}
	for(int i = 0; i < res.size(); i++){
		swap(res[i].first, res[i].second);
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		swap(res[i].first, res[i].second);
	}
	for(int i = 0; i < res.size(); i++){
		if(abs(angle[res[i].first] - angle[res[i].second]) > eps){
			cout << py[res[i].first] << ' ' << px[res[i].first] << ' ' << py[res[i].second] << ' ' << px[res[i].second] << endl;
		}
	}


}
