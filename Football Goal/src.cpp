#include <bits/stdc++.h>

typedef long long ll;

const double PI = std::acos(-1);

double res(double angle, double angle2, double a, double b){
	double first_triangle = a * a * std::sin(angle) * std::cos(angle) / 2.0;
	double second_square = a * b * std::cos(angle2) * std::sin(angle);
	double third_triangle = b * b * std::sin(angle2) * std::cos(angle2) / 2.0;
	return first_triangle + second_square + third_triangle;
}

double solve2(double angle, double a, double b){
	double l = 0.0, r = PI / 2.0;

	for(int i = 0; i < 200; i++){
		double mini_l = l + (r - l) / 3.0;
		double mini_r = l + 2.0 * (r - l) / 3.0;

		if(res(angle, mini_l, a, b) > res(angle, mini_r, a, b)){
			r = mini_r;
		} else {
			l = mini_l;
		}
	}

	return res(angle, l, a, b);
}

double solve(double a, double b){
	double l = 0.0, r = PI / 2.0;

	for(int i = 0; i < 200; i++){
		double mini_l = l + (r - l) / 3.0;
		double mini_r = l + 2.0 * (r - l) / 3.0;

		if(solve2(mini_l, a, b) > solve2(mini_r, a, b)){
			r = mini_r;
		} else {
			l = mini_l;
		}
	}

	return solve2(l, a, b);
}

int main(){
	int a, b;
	std::cin >> a >> b;

	std::cout.precision(9);
	std::cout << std::fixed << std::max(solve(a, b), solve(b, a)) << '\n';
}
