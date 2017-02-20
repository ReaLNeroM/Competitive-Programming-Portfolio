/*
ID: vlade.m1
PROG: fence3
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 155;
pair<int, int> p1[maxn], p2[maxn];
int special[maxn];
double slope[maxn], b[maxn];
double eps = 0.0000000000001;
int n;

double euclid(pair<double, double> a, pair<double, double> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double dist(int line_index, pair<double, double> p){
	if(special[line_index] == 1){
		if(p1[line_index].second > p.second){
			return euclid(p1[line_index], p);
		} else if(p2[line_index].second < p.second){
			return euclid(p2[line_index], p);
		} else {
			return euclid({(double) b[line_index], p.second}, p);
		}
	} else if(special[line_index] == 2){
		if(p1[line_index].first > p.first){
			return euclid(p1[line_index], p);
		} else if(p2[line_index].first < p.first){
			return euclid(p2[line_index], p);
		} else {
			return euclid({p.first, (double) b[line_index]}, p);
		}
	} else {
		double intersect_x;
		double other_slope, other_b;
		double other = slope[line_index] * p.first + b[line_index];
		if(abs(other - p.second) < eps * 1000.0){
			intersect_x = p.first;
		} else {
			other_slope = -1.0 / slope[line_index];
			other_b = p.second - other_slope * p.first;
			intersect_x = (other_b - b[line_index]) / (slope[line_index] - other_slope - eps);
		}
		if(intersect_x <= p1[line_index].first){
			return euclid(p1[line_index], p);
		} else if(intersect_x >= p2[line_index].first){
			return euclid(p2[line_index], p);
		} else {
			return euclid({intersect_x, slope[line_index] * intersect_x + b[line_index]}, p);
		}
	}
}

double best_seen = 1e18;
double check(double y, double x){
	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += dist(i, {x, y});
		if(sum > best_seen){
			return 1e18;
		}
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("fence3.in", "r", stdin);
    freopen("fence3.out", "w", stdout);

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> p1[i].first >> p1[i].second;
		cin >> p2[i].first >> p2[i].second;
		if(p1[i].first > p2[i].first){
			swap(p1[i].first, p2[i].first);
		}
		if(p1[i].second > p2[i].second){
			swap(p1[i].second, p2[i].second);
		}
		if(p2[i].first == p1[i].first){
			special[i] = 1;
			b[i] = p2[i].first;
		} else if(p1[i].second == p2[i].second){
			special[i] = 2;
			slope[i] = 0;
			b[i] = p2[i].second;
		} else {
			slope[i] = (p2[i].second - p1[i].second) / (p2[i].first - p1[i].first);
			b[i] = p2[i].second - slope[i] * p1[i].second;
		}
	}

	double best_y = 0.00, best_x = 0.00;
	for(double try_y = 0.00; try_y < 101.00; try_y += 0.1){
		double lower_x = best_x - 5;
		double upper_x = best_x + 5;
		for(double try_x = lower_x; try_x < upper_x; try_x += 0.1){
			double try_this = check(try_y, try_x);
			if(best_seen >= try_this){
				best_seen = try_this;
				best_y = try_y;
				best_x = try_x;
			}
		}
	}
	cout.precision(1);
	cout << fixed << best_x << ' ' << best_y << ' ' << best_seen << endl;
}

