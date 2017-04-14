#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	string a, b;
	cin >> a >> b;

	int res = 0;
	int best_start_cut = 0;
	int best_end_cut = b.size() - 1;

	int b_pos = 0;
	for(int i = 0; i < a.size() and b_pos < b.size(); i++){
		if(a[i] == b[b_pos]){
			b_pos++;
		}
	}

	best_start_cut = b_pos;
	best_end_cut = b.size() - 1;
	res = b_pos;

	b_pos = b.size() - 1;
	for(int i = a.size() - 1; i >= 0 and b_pos >= 0; i--){
		if(a[i] == b[b_pos]){
			b_pos--;
		}
	}

	if(b.size() - 1 - b_pos > res){
		best_start_cut = 0;
		best_end_cut = b_pos;
		res = b.size() - 1 - b_pos;
	}

	int b_start_pos = 0, b_end_pos = b.size() - 1;
	int a_end = a.size();

	vector<int> v;

	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[b_start_pos]){
			b_start_pos++;
			v.push_back(i);
		}
	}

	for(int i = b_start_pos; i > 0; i--){
		int lower_limit = *v.rbegin();

		b_start_pos = i;
		while(a_end > lower_limit and b_start_pos < b_end_pos){
			if(a[a_end] == b[b_end_pos]){
				b_end_pos--;
			}
			a_end--;
		}
		v.pop_back();

		if(b_start_pos + b.size() - 1 - b_end_pos > res){
			res = b_start_pos + b.size() - 1 - b_end_pos;
			best_start_cut = b_start_pos;
			best_end_cut = b_end_pos;
		}
	}

	string end_s = "";
	for(int i = 0; i < b.size(); i++){
		if(best_start_cut <= i and i <= best_end_cut){
			continue;
		} else {
			end_s += b[i];
		}
	}

	if(end_s == ""){
		cout << "-";
	} else {
		cout << end_s;
	}
}
