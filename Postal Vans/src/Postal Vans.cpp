/*
ID: vlade.m1
PROG: vans
LANG: C++
*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e4;
string dp4[maxn];
string dp4o[maxn];
string dp[maxn];

string operator+ (string a, string b){
	string x = "";
	int carry = 0;
	for(int i = 0; i < a.size() or i < b.size() or carry; i++){
		char c = '0';
		if(i < a.size()){
			c += a[i] - '0';
		}
		if(i < b.size()){
			c += b[i] - '0';
		}
		c += carry;
		if(c > '9'){
			c -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		x += c;
	}
	return x;
}

int main(){
    freopen("vans.in", "r", stdin);
    freopen("vans.out", "w", stdout);

	ll n;
	cin >> n;

	for(ll i = 0; i <= n; i++){
		if(i <= 0){
			dp4o[i] = "0";
		} else if(i == 1){
			dp4o[1] = "1";
		} else {
			dp4o[i] = dp4o[i - 1] + (dp4[i - 2] + dp[i - 2]) + (dp4[i - 2] + dp[i - 2]);
		}
		if(i <= 0){
			dp[i] = "0";
		} else if(i == 1){
			dp[i] = "1";
		} else {
			dp[i] = dp4o[i - 1] + dp[i - 2] + (dp4[i - 2] + dp[i - 2]) + (dp4[i - 2] + dp[i - 2]);
		}
		if(i <= 1){
			dp4[i] = "0";
		} else {
			dp4[i] = dp4[i - 1] + dp[i - 1];
		}
	}
	string r = dp4[n] + dp4[n];
	reverse(r.begin(), r.end());
	cout << r << endl;
}

