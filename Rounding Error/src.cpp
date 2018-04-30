#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const double eps = 0.000000001;
int val[maxn];
std::vector<std::pair<int, double>> bad;
std::vector<double> satisfied;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test = 1; test <= t; test++){
		int n, l;
		std::cin >> n >> l;

		double piece = 100.0 / n;
		int left = n;

		bad.clear();
		satisfied.clear();
		double res = 0.0;

		for(int i = 0; i < l; i++){
			std::cin >> val[i];

			double converted = ((double) val[i]) * piece + eps;

			res += std::round(converted);

			if(std::floor(converted) == std::round(converted)){
				std::cout << (std::floor(converted) + 0.5 + eps) - (converted) << '\n';
				int need = std::floor(((std::floor(converted) + 0.5 + eps) - (converted)) / piece + eps);
				converted += ((double) need) * piece;
				bad.push_back({need, converted});
			} else {
				satisfied.push_back(converted);
			}

			left -= val[i];
		}

		std::sort(bad.begin(), bad.end());

		int changed = 0;

		for(int i = 0; i < bad.size(); i++){
			if(left >= bad[i].first){
				left -= bad[i].first;
				satisfied.push_back(bad[i].second);
				changed++;
				res += 1.0;
			}
		}

		if(changed == bad.size()){
			while(left >= 1){
				for(int i = 0; i < satisfied.size() and left >= 1; i++){
					while(left and std::round(satisfied[i] + piece) == std::round(satisfied[i])){
						satisfied[i] += piece;
						left--;
					}
				}

				if(left >= 1){
					satisfied[0] += piece;
					res -= 1.0;
					left--;
				}
			}
		}


		std::cout << "Case #" << test << ": " << (int) std::round(res + eps) << '\n';
	}
}
