#include <iostream>
#include <map>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
	int n, l;
	cin >> n >> l;

	multimap<int, int> next;
	multimap<int, int, greater<int> > prev;


	bool used[n];
	int p[n][2];
	for(int i = 0; i < n; i++){
		used[i] = false;

		double x;
		cin >> p[i][0] >> x;
		p[i][1] = x * 100 + 0.0000001;

		next.insert(make_pair(p[i][0], i));
		prev.insert(make_pair(p[i][0], i));
	}

	priority_queue<q> pq;
	for(int i = 0; i < n - 1; i++){
		pq.pus
	}


	return 0;
}
