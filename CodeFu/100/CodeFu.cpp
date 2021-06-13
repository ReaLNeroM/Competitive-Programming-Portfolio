#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

class AstralKombatII {
public:
	int fight(vector<int> A, vector<int> B){
		int n = A.size();
		int suma = 0;
		for(int i = 0; i < n; i++){
			suma += A[i];
		}
		std::sort(B.begin(), B.end());
		int res = 0;
		for(int i = 0; i < n; i++){
			if(suma > B[i]){
				suma -= B[i] + 1;
				res++;
			}
		}
		return res;
	}
};
	