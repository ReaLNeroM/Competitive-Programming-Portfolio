#include <bits/stdc++.h>

typedef long long ll;

struct dsu {
	dsu* parent = this;
	ll rank = 0;
	ll size = 1;

	dsu* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}

	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		if(fir != sec){
			fir->size = sec->size = fir->size + sec->size;

			if(fir->rank < sec->rank){
				std::swap(fir, sec);
			}

			if(fir->rank == sec->rank){
				fir->rank++;
			}

			sec->parent = fir;
		}
	}
};

using namespace std;

const ll maxn = 1e6 + 1e2;
dsu dsu_array[maxn];
std::map<ll, ll> m;

// Complete the competitiveTeams function below.
void competitiveTeams(ll n, ll q) {
	std::ios::sync_with_stdio(false);

	m[1] = n;
	
	ll components = n;
	for(ll i = 0; i < q; i++){
		ll type;
		std::cin >> type;

		if(type == 1){
			ll f, s;
			std::cin >> f >> s;
			f--, s--;

			dsu *fir, *sec;
			fir = dsu_array[f].head();
			sec = dsu_array[s].head();

			if(fir == sec){
				continue;
			}

			components--;

			m[fir->size]--;
			auto ite = m.find(fir->size);
			if(ite->second == 0){
				m.erase(ite);
			}
			
			m[sec->size]--;
			auto site = m.find(sec->size);
			if(site->second == 0){
				m.erase(site);
			}

			fir->merge(sec);
			m[dsu_array[f].head()->size]++;
		} else {
			ll distance;
			std::cin >> distance;

			if(distance == 0){
				std::cout << components * (components - 1LL) / 2LL << '\n';
			} else {
				ll res = components * (components - 1LL) / 2LL;
				auto r = m.begin();
				ll sum = 0;
				for(auto l = m.begin(); l != m.end(); l++){
					while(r != m.end() and r->first - l->first < distance){
						sum += r->second;
						r++;
					}
					sum -= l->second;
					res -= l->second * (l->second - 1LL) / 2LL;
					res -= sum * l->second;
				}

				std::cout << res << '\n';
			}
		}
	}
}

vector<string> split_string(string);

int main(){
	string nq_temp;
	getline(cin, nq_temp);

	vector<string> nq = split_string(nq_temp);

	int n = stoi(nq[0]);

	int q = stoi(nq[1]);

	competitiveTeams(n, q);

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
