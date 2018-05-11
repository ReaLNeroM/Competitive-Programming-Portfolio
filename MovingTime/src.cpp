#include <string>
#include <vector>
#include <cmath>

typedef long long ll;

class MovingTime {
	double get_in(double a, double b, double c){
		double sum = (a + b + c) / 2.0;
		return std::sqrt(sum * (sum - a) * (sum - b) * (sum - c)) / sum;
	}
	double get_out(double a, double b, double c){
		double sum = (a + b + c) / 2.0;
		return (a * b * c) / 4.0 / std::sqrt(sum * (sum - a) * (sum - b) * (sum - c));
	}
	double func(double a, double b, double c){
		double in_radius = get_in(a, b, c);
		double out_radius = get_out(a, b, c);

		return out_radius * out_radius - in_radius * in_radius;
	}
	double eps = 0.000000001;
public:
	std::string maximizeRouterSpeed(std::string sa, std::string sb){
		double a = atof(sa.c_str()), b = atof(sb.c_str());

		double best = 1e20;
		double best_c = 0.0;

		double l = 0.0 + eps, r = (a + b) / 2.0 - eps;

		while(l < r and r - l > eps){
			double mid1 = l + (r - l) / 3.0;
			double mid2 = l + 2.0 * (r - l) / 3.0;

			if(func(a, b, mid1) < func(a, b, mid2)){
				r = mid2;
			} else {
				l = mid1;
			}
		}

		std::string res = "";

		double res_double = l;
		res_double *= 100.0;

		int x = std::floor(res_double + 0.5);
		int ite = 0;
		while(x > 0){
			if(ite == 2){
				res.insert(res.begin(), '.');
			}
			res.insert(res.begin(), '0' + x % 10);
			x /= 10;
			ite++;
		}

		return res;
	}
};
