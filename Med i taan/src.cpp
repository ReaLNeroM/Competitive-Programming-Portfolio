#include <bits/stdc++.h>

typedef long long ll;

const double eps = 0.0000000001;
<<<<<<< HEAD
std::vector<std::vector<int>> a, b;

bool cmpa(std::vector<int> const &x, std::vector<int> const &y){
	return x[1] * y[2] < y[1] * x[2];
}
bool cmpb(std::vector<int> const &x, std::vector<int> const &y){
=======
std::vector<std::vector<double> > a, b;

bool cmpa(std::vector<double> const &x, std::vector<double> const &y){
	return x[1] * y[2] < y[1] * x[2];
}
bool cmpb(std::vector<double> const &x, std::vector<double> const &y){
>>>>>>> 609e9eb9bedbe9d63afcd5ec1bd08ee57fc21396
	return x[1] * y[2] > y[1] * x[2];
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	double res = 0.0;
	for(int i = 0; i < n; i++){
<<<<<<< HEAD
		std::vector<int> tegla(3);
=======
		std::vector<double> tegla(3);
>>>>>>> 609e9eb9bedbe9d63afcd5ec1bd08ee57fc21396
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
<<<<<<< HEAD
		double ra = (double) a[0][1] - a[0][2];
		double qb = b[0][0];
		double rb = (double) b[0][2] - b[0][1];
=======
		double ra = ((double) (a[0][1] - a[0][2])) / (a[0][1] + a[0][2]);
		double qb = b[0][0];
		double rb = ((double) (b[0][2] - b[0][1])) / (b[0][1] + b[0][2]);
>>>>>>> 609e9eb9bedbe9d63afcd5ec1bd08ee57fc21396

		double ifBLimits = qb * rb / ra;
		double ifALimits = qa * ra / rb;

<<<<<<< HEAD
		std::cout << qa << ' ' << ra << ' ' << qb << ' ' << rb << ' ' << ifBLimits << ' ' << ifALimits << '\n';

=======
>>>>>>> 609e9eb9bedbe9d63afcd5ec1bd08ee57fc21396
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
<<<<<<< HEAD
		if(std::abs(takenA - qa) < eps){
			a.erase(a.begin());
		}
		if(std::abs(takenB - qb) < eps){
=======

		a[0][0] -= takenA;
		b[0][0] -= takenB;

		if(a[0][0] < eps){
			a.erase(a.begin());
		}

		if(b[0][0] < eps){
>>>>>>> 609e9eb9bedbe9d63afcd5ec1bd08ee57fc21396
			b.erase(b.begin());
		}
	}

	std::cout.precision(9);
	std::cout << std::fixed << res << '\n';
}
