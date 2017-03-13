#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int start = 0, end;
	cin >> end;

	int x1, x2;
	cin >> x1 >> x2;

	int t1, t2;
	cin >> t1 >> t2;

	cin >> start;
	int dir;
	cin >> dir;

	if(dir == -1){
		end = 0;
	}

	int res = abs(x1 - x2) * t2;

	if(t2 >= t1 or (start > end and x1 < x2) or (start < end and x2 > x1) or abs(end - x1) * t2 <= abs(end - start) * t1){
		cout << res << endl;
		return 0;
	}
	cout << res;

	double x = start - x1;
	x /= (double) (t2 - t1);
	double curr = start + x * t1;

	double sec;
	if(end < x2){
		sec = abs(curr - x1) * t2 + abs(curr - end) * t1 + abs(end - x2) * t2;
	} else {
		sec = abs(curr - x1) * t2 + abs(curr - x2) * t1;
	}

	sec = min(sec, (double) res);

	cout << fixed << sec;

}
