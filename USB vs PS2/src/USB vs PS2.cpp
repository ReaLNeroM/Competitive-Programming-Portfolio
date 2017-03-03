#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> va, vb;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int cost;
		string s;
		cin >> cost >> s;

		if(s == "USB"){
			va.push_back(cost);
		} else {
			vb.push_back(cost);
		}
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int a_pos = 0, b_pos = 0;

	int equipped = 0;
	ll sum = 0;
	for(int j = 0; j < a and j < va.size(); j++){
		equipped++;
		sum += va[j];
		a_pos++;
	}
	for(int j = 0; j < b and j < vb.size(); j++){
		equipped++;
		sum += vb[j];
		b_pos++;
	}

	for(int j = 0; j < c; j++){
		if(a_pos != va.size() and b_pos != vb.size()){
			equipped++;
			if(va[a_pos] <= vb[b_pos]){
				sum += va[a_pos];
				a_pos++;
			} else {
				sum += vb[b_pos];
				b_pos++;
			}
		} else if(a_pos != va.size()){
			equipped++;
			sum += va[a_pos];
			a_pos++;
		} else if(b_pos != vb.size()){
			equipped++;
			sum += vb[b_pos];
			b_pos++;
		}
	}

	cout << equipped << ' ' << sum << endl;
}
