#include <string>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

class Sequence{
public:
	int findElement(int k, vector<int> coefficients, vector<int> elements, int p){
		ll mod=1000007;
		vector<ll> v;
		for(int i=0;i<elements.size();i++){
			v.push_back(elements[i]);
		}
		int i=k+1;
		int bb=1;
		for(int i=0;i<p;i++)
			bb*=10;
		 i=k+1;
		while(i<=bb){
			if(i % 1048576LL == 0){
				std::cerr << (ll) i * 100LL / bb << std::endl;
			}
			ll nov=0;
			int a=0;
			for(int j=v.size()-1;j>=0;j--){
				if(a==k)
					break;
				ll br=(v[j]*coefficients[a])*1LL;
				br%=mod;
				nov+=br;
				nov%=mod;
				a++;
			}
			if(i==bb)
				return nov;
			v.push_back(nov);
			i++;
		}
		return v[bb-1];
	}
};

int main(){
	Sequence x;
	x.findElement(9, {1,9727,9556,9620,6014,6045,7266,7511,9191}, {9535,5662,6592,8045,3364,6765,174,1123,1581}, 17);
}
