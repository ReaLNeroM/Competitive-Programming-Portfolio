#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e6;
const double eps = 0.000000000000001;
map<double, ll> m;

int main(){
	ll q, mana;
	std::cin >> q >> mana;

	ll j = 0;

	for(ll i = 0; i < q; i++){
		ll t, a, b;
		std::cin >> t >> a >> b;

		a = (a + j) % mod + 1;
		b = (b + j) % mod + 1;

		if(t == 1){
			double fract = (double) a / (double) b;

			auto ite = m.lower_bound(fract - eps);
			auto prite = ite;
			if(ite != m.begin()){
				--prite;
				while(true){
					if(prite->second < a){
						auto secprite = prite;
						--prite;
						if(secprite == m.begin()){
							m.erase(secprite);
							break;
						}
					} else {
						break;
					}
				}				
			}
			while(ite != m.end()){
				if(ite->second < a){
					auto secite = ite;
					++ite;
					m.erase(secite);
				} else {
					break;
				}
			}
			if(ite == m.end() or ite->second >= a){
				m[fract] = a;
			}
		} else {
			double fract = (double) b / (double) mana;
			double goal_damage = (double) b / (double) a;
			auto ite = m.lower_bound(fract - eps);

			if(ite != m.end() and ite->first >= fract and ite->second >= goal_damage){
				cout << "YES\n";
				j = i + 1;
			} else {
				cout << "NO\n";
			}
		}
	}
}
