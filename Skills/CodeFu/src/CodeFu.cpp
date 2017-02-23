#include <string>
#include <vector>
#include <cmath>
using namespace std;

class CisaroMath {
	bool close(double x) {
		if(abs(round(x) - x) < 0.00001) {
			return true;
		}

		return false;
	}
public:
	string solve(int a, int b, int n){
		double r = 0;
		if(a == 0 and b == 0){
			return "0";
		} else if(a == 0){
			return "No solution";
		}

		r = (double) b / a;
		if(close(r)){
			if(abs(r) != 1){
				r = pow(r, 1.0 / (double) n);
			}
			if (close(r)) {
				std::string res = "";
				long long x = round(r);

				while (abs(x) >= 1) {
					res.insert(res.begin(), '0' + x % 10);
					x /= 10;
				}
				if (res == "") {
					res += '0';
				}
				return res;
			} else {
				return "No solution";
			}
		}
	}
};

int main(){
	CisaroMath x;
	x.solve(-1, 8, 3);
}
