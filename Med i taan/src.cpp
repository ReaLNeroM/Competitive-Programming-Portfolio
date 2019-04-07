#include <bits/stdc++.h>

typedef long long ll;

const double eps = 0.0000000001;
std::vector<std::vector<double> > a, b;

bool cmpa(std::vector<double> const &x, std::vector<double> const &y){
	return x[1] * y[2] < y[1] * x[2];
}
bool cmpb(std::vector<double> const &x, std::vector<double> const &y){
	return x[1] * y[2] > y[1] * x[2];
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	double res = 0.0;
	for(int i = 0; i < n; i++){
		std::vector<double> tegla(3);
		std::cin >> tegla[0] >> tegla[1] >> tegla[2];

		// equal parts
		if(tegla[1] == tegla[2]){
			res += tegla[0];
			continue;
		} else if(tegla[1] > tegla[2]){
			a.push_back(tegla);
		} else {
			b.push_back(tegla);
		}
	}

	std::sort(a.begin(), a.end(), cmpa);
	std::sort(b.begin(), b.end(), cmpb);

	while(!a.empty() and !b.empty()){
		double qa = a[0][0];
		double ra = ((double) (a[0][1] - a[0][2])) / (a[0][1] + a[0][2]);
		double qb = b[0][0];
		double rb = ((double) (b[0][2] - b[0][1])) / (b[0][1] + b[0][2]);

		double ifBLimits = qb * rb / ra;
		double ifALimits = qa * ra / rb;

		double takenA = 0.0;
		double takenB = 0.0;

		if(0 <= ifALimits and ifALimits <= qb){
			takenA = qa;
			takenB = ifALimits;
		} else if(0 <= ifBLimits and ifBLimits <= qa){
			takenA = ifBLimits;
			takenB = qb;
		}

		res += takenA + takenB;

		a[0][0] -= takenA;
		b[0][0] -= takenB;

		if(a[0][0] < eps){
			a.erase(a.begin());
		}

		if(b[0][0] < eps){
			b.erase(b.begin());
		}
	}

	std::cout.precision(9);
	std::cout << std::fixed << res << '\n';
}
