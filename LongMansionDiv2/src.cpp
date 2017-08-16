#include <bits/stdc++.h>

typedef long long ll;

class LongMansionDiv2{
public:
	long long minimalTime(int M, std::vector <int> t){
		ll n = t.size();
		ll m = M;

		ll res = 0;

		ll other = 1e18;

		for(int i = 0; i < t.size(); i++){
			res += t[i];
			other = std::min(other, (m - 1) * t[i]);
		}

		return res + other;
	}
};