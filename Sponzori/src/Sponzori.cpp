#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

const double PI = 3.14159265;

struct candidate{
	int gift;
	bool gender, comp;
	double angle;

	bool operator<(const candidate &x) const {
		if(comp){
			return true;
		} else if(x.comp){
			return false;
		}

		return angle < x.angle;
	}
};

double make_angle(int y, int x, int y1, int x1){
	return (atan2(y - y1, x - x1) + PI) * 180 / PI;
}

int main(){
	int cand;
	cin >> cand;

	int y[cand], x[cand], g[cand];
	bool gen[cand];

	candidate v[cand];
	for(int i = 0; i < cand; i++){
		char gender;
		cin >> y[i] >> x[i] >> g[i] >> gender;
		gen[i] = (gender == 'Z');
	}

	int maxx = 0;
	for(int i = 0; i < cand; i++){
		int girlsum = 0, malesum = 0, fullgsum = 0, fullmsum = 0;

		for(int j = 0; j < cand; j++){
			v[j].gift = g[j];
			v[j].gender = gen[j];
			v[j].angle = make_angle(y[i], x[i], y[j], x[j]);
			v[j].comp = false;

			fullgsum += v[j].gender * v[j].gift;
			fullmsum += !v[j].gender * v[j].gift;
		}
		fullgsum -= v[i].gender * v[i].gift;
		fullmsum -= !v[i].gender * v[i].gift;

		v[i].comp = true;
		sort(v, v + cand);

		int right = 1;
		for(int left = 1; left < cand; left++){
			while(right < cand and v[right].angle <= 180 + v[left].angle){
				girlsum +=  v[right].gender * v[right].gift;
				malesum += !v[right].gender * v[right].gift;

				right++;
			}

			maxx = max(maxx, max(fullmsum - malesum + girlsum, fullgsum - girlsum + malesum));

			girlsum -= v[left].gender * v[left].gift;
			malesum -= !v[left].gender * v[left].gift;
		}
	}

	cout << maxx;
}
