#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

class RepeatNumberCompare {
public:
	std::string compare(int x1, int k1, int x2, int k2){
		std::stringstream istr;
		istr << x1;

		std::string a;
		istr >> a;

		std::stringstream istr2;
		istr2 << x2;

		std::string b;
		istr2 >> b;

		std::string ao = "", bo = "";
		for(int i = 0; i < k1; i++){
			ao += a;
		}
		for(int i = 0; i < k2; i++){
			bo += b;
		}

		if(ao.size() > bo.size() or (ao.size() == bo.size() and ao > bo)){
			return "Greater";
		} else if(ao.size() < bo.size() or (ao.size() == bo.size() and ao < bo)){
			return "Less";
		} else {
			return "Equal";
		}
	}
};