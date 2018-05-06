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
public:
	std::string maximizeRouterSpeed(std::string sa, std::string sb){
		double a = atof(sa.c_str()), b = atof(sb.c_str());

		double best = 1e20;
		double best_c = 0.0;

		for(double c = 0.000; c < (a + b); c += 0.00001){
			double in_radius = get_in(a, b, c);
			double out_radius = get_out(a, b, c);

			if(std::abs(in_radius * in_radius - out_radius * out_radius) < best){
				best = std::abs(in_radius * in_radius - out_radius * out_radius);
				best_c = c;
			}
		}

		std::string res = "";
		best_c *= 100.0;

		int x = std::floor(best_c + 0.5);
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
