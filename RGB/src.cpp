#include <string>
#include <vector>
using namespace std;
typedef long long ll;

class RGB{
public:
	int countWays(int N){
		ll x = (N + 2);
		x *= (N + 1);
		x /= 2;
		return (int) x;
	}
};