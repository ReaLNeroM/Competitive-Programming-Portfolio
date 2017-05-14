#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;
	int n = a.size();

	std::sort(a.begin(), a.end());
	std::sort(b.rbegin(), b.rend());

	std::string res = std::string(n, '?');
	int lpos = 0, rpos = n - 1;
	int apos = 0, bpos = 0;
	int aendpos = (n + 1) / 2 - 1;
	int bendpos = n / 2 - 1;
	int side = 0;

	while(lpos <= rpos){
		if(side == 0){
			if(a[apos] >= b[bpos]){
				res[rpos] = a[aendpos];

				rpos--;
				aendpos--;
			} else {
				res[lpos] = a[apos];

				lpos++;
				apos++;
			}
		} else {
			if(a[apos] >= b[bpos]){
				res[rpos] = b[bendpos];

				rpos--;
				bendpos--;
			} else {
				res[lpos] = b[bpos];

				lpos++;
				bpos++;
			}
		}

		side ^= 1;
	}

	std::cout << res << std::endl;
}