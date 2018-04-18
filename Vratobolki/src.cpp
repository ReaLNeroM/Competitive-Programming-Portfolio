#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int n;
std::string s;
int pre[maxn];
int suf[maxn];
int found[maxn];
int suffound[maxn];

bool within(int a, int l, int r){
	return l <= a and a <= r;
}

double below(ll a, ll b){
	double res = pre[b + 1] - pre[a];
	res -= found[a] * (double) (b - a);

	return res;
}

double above(ll a, ll b){
	double res = suf[a - 1] - suf[b];
	res -= (double) suffound[b] * (b - a + 1);

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	std::cin >> s;

	bool same = true;

	for(int i = 0; i + 1 < n; i++){
		if(s[i] != s[i + 1]){
			same = false;
		}
	}

	if(same){
		std::cout << "0 0\n";
		return 0;
	}

	double res = 1e18;

	int l_count = std::count(s.begin(), s.end(), 'L');

	int running_count = 0;
	pre[0] = 0;
	for(int i = 0; i < 2 * n; i++){
		pre[i + 1] = pre[i] + running_count;
		if(s[i % n] == 'L'){
			running_count++;
			s_L.insert(i);
		}
		found[i + 1] = running_count;
	}

	running_count = 0;
	suf[2 * n] = 0;
	suffound[2 * n] = 0;
	for(int i = 2 * n; i > 0; i--){
		suf[i - 1] = suf[i] + running_count;
		if(s[i % n] == 'L'){
			running_count++;
		}
		suffound[i - 1] = running_count;
	}

	for(int i = 0; i < n; i++){
		//start from here
		double l = i, r = i + n - 1;
		for(int j = 0; j < 50; j++){
			double mid = (l + r) / 2.0;

			double below_query = below(i, std::floor(mid));
			double above_query = above(std::ceil(mid), i + n - 1);
			res = std::min(res, below_query + above_query);

			if(below_query < above_query){
				l = mid;
			} else {
				r = mid;
			}
		}
	}

	std::cout << 1 << ' ' << res << '\n';
}
