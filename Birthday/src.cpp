#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int n;
static int other[maxn];
static int val[maxn];

int try_out(){
	std::vector<int> v;

	for(int i = 0; i < n; i++){
		int pos = val[i] - i;
		
		while(pos < 0){
			pos += n;
		}

		v.push_back(pos);
	}

	std::sort(v.begin(), v.end());
	auto ite = std::unique(v.begin(), v.end());
	v.resize(std::distance(v.begin(), ite));

	int size = v.size();
	for(int i = 0; i < size; i++){
		v.push_back(v[i] + n);
	}

	int res = n;
	
	int curr = 0;

	for(int i = 0; i < n; i++){
		int need = i + (n / 2 - std::min(n / 2, 5));

		while(curr + 1 < v.size() and v[curr + 1] <= need){
			curr++;
		}

		int ans = 0;
		for(int j = curr; j < curr + 10 and j < v.size(); j++){			
			ans = std::max(ans, std::min(std::min(std::abs(v[j] % n - i - n), std::abs(v[j] % n - i)), std::abs(v[j] % n - i + n)));
		}

		res = std::min(res, ans);
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> other[i];
		val[other[i] - 1] = i;
	}

	int res = try_out();
	for(int i = 0; i < n; i++){
		val[i] = n - val[i] - 1;
	}
	res = std::min(res, try_out());

	std::cout << res;
}