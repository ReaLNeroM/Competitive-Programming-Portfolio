#include <iostream>
using namespace std;

int main() {
	int igri, bodovi, pob = 0;
	cin>>igri>>bodovi;
	igri = 2*igri - 2;

	cout<<(igri - bodovi) / 3<<" ";
	while(igri < bodovi){
		pob++;
		bodovi -= 3;
		igri--;
	}

	cout<<pob<<endl;

	cout<<pob<<" "<<bodovi<<" "<<igri - bodovi;
	return 0;
}
