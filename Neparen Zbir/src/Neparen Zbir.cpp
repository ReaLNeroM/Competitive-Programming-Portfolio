#include <iostream>
using namespace std;
int main() {
	int a, b;
	long long res = 0;
	cin>>a>>b;
	if(a % 2 == 0)
		a++;
	for(; a <= b; a += 2){
		res += a;
	}
	cout<<res;
	return 0;
}
