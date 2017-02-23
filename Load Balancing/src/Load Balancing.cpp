#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int servers;
	cin >> servers;

	int load[servers], sum = 0;
	for(int i = 0; i < servers; i++){
		cin >> load[i];
		sum += load[i];
	}
	sort(load, load + servers, greater<int>());

	int left = sum % servers;
	int perc = sum / servers;

	int change = 0;
	for(int i = 0; i < servers; i++){
		if(load[i] > perc + (i < left)){
			change += load[i] - perc - (i < left);
		}
	}

	cout << change;
	return 0;
}
