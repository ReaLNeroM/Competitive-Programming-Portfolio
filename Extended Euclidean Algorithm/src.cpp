#include <bits/stdc++.h>

typedef long long ll;

int l_a, l_b, d_a, d_b;

void extended(int a, int b){
	if(b == 0){
		std::cout << l_a << ' ' << l_b << ' ' << a << std::endl;
		return;
	}

	int nl_a, nl_b, nd_a, nd_b;

	nl_a = d_a;
	nl_b = d_b;

	nd_a = l_a - a/b * d_a;
	nd_b = l_b - a/b * d_b;

	l_a = nl_a;
	l_b = nl_b;
	d_a = nd_a;
	d_b = nd_b;

	extended(b, a % b);
}

int main(){
	ll a, b;
	std::cin >> a >> b;

	l_a = 1;
	l_b = 0;
	d_a = 0;
	d_b = 1;

	extended(a, b);
}