#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	 int zadaci, teskizad, tezin;
	 cin>>zadaci>>teskizad;
	 vector<int> tezina;
	 for(int i = 0; i < zadaci;i++){
		 cin>>tezin;
		 tezina.push_back(tezin);
	 }

	 sort(tezina.begin(),tezina.end());

	 cout<<tezina[zadaci - teskizad] - tezina[zadaci - teskizad - 1];

	 return 0;
}
