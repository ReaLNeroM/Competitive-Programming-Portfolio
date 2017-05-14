#include <string>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;

class MailmanEasy{
public:
	string totalHouses(int H, int W){
		ll x = H;
		ll y = W;
		ll z = x * y;

		if(x % 2 == 0 or y % 2 == 0){
			std::stringstream ostr;
			ostr << z;
			string s;
			ostr >> s;
			
			return s;
		} else {
			return "0";
		}
	}
};
