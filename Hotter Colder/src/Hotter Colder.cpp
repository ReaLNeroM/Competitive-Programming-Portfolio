#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

 int main() {
	 double minx = 1e9;
	 for(int i = 1; i <= 8; i++){
		 double n = (double) 3/7 * i;

		 if(abs(n - round(n)) < 0.000001){
			 minx = min(minx, n - 1);
		 } else {
			 minx = min(minx, floor(n));
		 }
	 }

	 cout << minx;

	return 0;
}
