#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 600005;
const ll mod = 1e9 + 7;
int val[maxn];
int board[maxn];

bool read(){
	std::string s;
	std::cin >> s;

	if(s == "TAK"){
		return true;
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	if(n == 2){
		std::cout << "2 1 2" << std::endl;
		return 0;
	}

	int a12, ar12;
	std::cout << "1 1 2\n";
	std::cout << "1 " << n << ' ' << n - 1 << '\n';
	std::cout.flush();
	a12 = read();
	ar12 = read();

	if(a12 and ar12){
		std::cout << 2 << ' ' << 1 << ' ' << n << std::endl;
	} else if(a12){
		int currp = n - 1;
		int ite = 1;
	} else if(ar12){

	} else {

	}
}