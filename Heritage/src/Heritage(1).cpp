#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

double p[501][2];

double solve(double area[], int kids, double coord[]){
	int fencepos = 0;
	double pos[] = {p[fencepos][0], p[fencepos][1]};

	double fencel = 0;
	for(int k = 0; k < kids - 1; k++){
		double left = area[k];
		while((pos[1] + p[fencepos + 1][1]) / 2 * (p[fencepos + 1][0] - pos[0]) + 0.000001 < left){
			left -= (pos[1] + p[fencepos + 1][1]) / 2 * (p[fencepos + 1][0] - pos[0]);
			fencepos++;
			pos[0] = p[fencepos][0];
			pos[1] = p[fencepos][1];
		}

		double s = (p[fencepos + 1][1] - p[fencepos][1]) / (p[fencepos + 1][0] - p[fencepos][0]);

		double x = (sqrt(pos[1] * pos[1] + 2 * s * left) - pos[1]) / s;

		pos[0] += x;
		pos[1] += x * s;
		coord[k] = pos[0];
		fencel += pos[1];
	}

	return fencel;
}

int main() {
	ios::sync_with_stdio(false);

	int sons, points;
	cin >> sons >> points;

	double agesum = 0;
	double age[sons];
	for(int i = 0; i < sons; i++){
		cin >> age[i];
		agesum += age[i];
	}

	double sum = 0;
	for(int i = 0; i < points; i++){
		cin >> p[i][0] >> p[i][1];
	}

	for(int i = 0; i < points; i++){
		int minindex = i;

		for(int j = i + 1; j < points; j++){
			if(p[j][0] < p[minindex][0]){
				minindex = j;
			}
		}

		swap(p[i], p[minindex]);
	}

	for(int i = 0; i < points - 1; i++){
		sum += ((p[i + 1][0] - p[i][0]) * (p[i + 1][1] + p[i][1])) / 2;
	}

	double area[sons];
	double bestfence[sons];
	for(int i = 0; i < sons; i++){
		area[i] = sum / (agesum / age[i]);
		bestfence[i] = 0;
	}
	sort(area, area + sons);

	double minfence = 32000 * sons;
	do {
		double coord[sons];
		double check = solve(area, sons, coord);
		if(check + 0.0000001 < minfence){
			minfence = check;
			for(int i = 0; i < sons; i++){
				bestfence[i] = coord[i];
			}
		}
	} while(next_permutation(area, area + sons));

	cout.precision(16);
	cout << minfence << endl;
	for(int i = 0; i < sons - 1; i++){
		cout << bestfence[i] << ' ';
	}
	return 0;
}
