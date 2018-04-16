#include <bits/stdc++.h>

typedef long long ll;

const double EPS = 0.00000000001;

int main(){
	std::ios::sync_with_stdio(false);

	ll test_cases;
	std::cin >> test_cases;

	for(ll test_case = 1; test_case <= test_cases; test_case++){
		int n;
		double goal;
		std::cin >> n >> goal;

		std::map<double, double> m;
		m[0.0] = 0.0;

		double start_perimeter = 0.0;
		for(int i = 0; i < n; i++){
			double a, b;
			std::cin >> a >> b;
			start_perimeter += 2.0 * (a + b);

			if(a > b){
				std::swap(a, b);
			}

			auto ite = m.rbegin();
			while(ite != m.rend()){
				double new_a = ite->first + 2.0 * a;
				double new_b = ite->second + 2.0 * std::sqrt(a * a + b * b);

				auto sec = m.lower_bound(new_b - EPS);
				if(std::abs(new_b - sec->first) < EPS and sec != m.end()){
					sec->second = std::min(m[new_b], new_a);
				} else {
					m[new_b] = new_a;
					sec = m.find(new_b);
				}

				while(sec != m.begin()){
					auto thi = sec;
					thi--;

					if(sec->second - EPS <= thi->first + EPS){
						sec->second = std::min(sec->second, thi->second);
						m.erase(thi);
					} else {
						break;
					}
				}

				while(sec != (--m.end())){
					auto thi = sec;
					thi++;

					if(thi->second - EPS <= sec->first + EPS){
						thi->second = std::min(thi->second, sec->second);
						m.erase(sec);
						sec = thi;
					} else {
						break;
					}
				}

				ite++;
			}
		}

		goal -= start_perimeter;

		double res = 0.0;

		auto ite = m.lower_bound(goal - EPS);
		if(ite == m.end() or goal + EPS < ite->second - EPS){
			res = (--ite)->first;
		} else {
			res = goal;
		}

		std::cout.precision(9);
		std::cout << "Case #" << test_case << ": ";
		std::cout << std::fixed << start_perimeter + res;
		std::cout << '\n';
	}
}