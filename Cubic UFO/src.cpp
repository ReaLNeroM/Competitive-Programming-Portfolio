#include <bits/stdc++.h>

typedef long long ll;

const long double pi = acos(-1);
long double points[11][3] = {{ 0.5,  0.5,  0.5},
					   { 0.5,  0.5, -0.5},
					   { 0.5, -0.5,  0.5},
					   { 0.5, -0.5, -0.5},
					   {-0.5,  0.5,  0.5},
					   {-0.5,  0.5, -0.5},
					   {-0.5, -0.5,  0.5},
					   {-0.5, -0.5, -0.5},
					   { 0.5,  0.0,  0.0},
					   { 0.0,  0.5,  0.0},
					   { 0.0,  0.0,  0.5}
					};
					   

long double npoints[11][3];
long double rotation_matrix[3][3];

long double attempt(long double angle){
	memset(npoints, 0, sizeof(npoints));

	rotation_matrix[1][1] = 1.0;
	rotation_matrix[0][0] = rotation_matrix[2][2] = std::cos(angle);
	rotation_matrix[0][2] = rotation_matrix[2][0] = std::sin(angle);
	rotation_matrix[0][2] *= -1.0;
	// rotation_matrix[2][2] = 1.0;
	// rotation_matrix[0][0] = rotation_matrix[1][1] = std::cos(angle);
	// rotation_matrix[0][1] = rotation_matrix[1][0] = std::sin(angle);
	// rotation_matrix[1][0] *= -1;

	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				npoints[i][j] += points[i][k] * rotation_matrix[k][j];
			}
		}
	}

	long double z_max = -1.0;
	long double z_min =  1.0;

	for(int i = 0; i < 8; i++){
		z_max = std::max(z_max, npoints[i][2]);
		z_min = std::min(z_min, npoints[i][2]);
	}
	long double z_length = z_max - z_min;

	return 1.0 * z_length;
}


int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test_case = 1; test_case <= t; test_case++){
		long double area;
		std::cin >> area;

		long double res = 0.0;

		long double l = 0.0, r = (pi + 0.000001) / 4.0;

		for(int i = 0; i < 100; i++){
			long double mid = (l + r) / 2.0;

			if(attempt(mid) > area){
				r = mid;
			} else {
				l = mid;
			}
		}

		std::cout.precision(9);
		std::cout << "Case #" << test_case << ":\n";

		for(int i = 8; i < 11; i++){
			for(int j = 0; j < 3; j++){
				std::cout << std::fixed << npoints[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
}
