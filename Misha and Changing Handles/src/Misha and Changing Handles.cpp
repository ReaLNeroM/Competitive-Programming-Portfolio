#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	map<string, int> s;
	set<string> used;

	int good = 0;

	string ag[n];
	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;

		if((s.find(a) != s.end() or used.find(a) == used.end()) and used.find(b) == used.end()){
			if(s.find(a) == s.end()){
				s[a] = good;
				ag[good] = a;
				good++;
			}

			s[b] = s[a];
			s.erase(s.find(a));
			used.insert(a);
			used.insert(b);
		}
	}

	cout << good << endl;
	map<string, int>::iterator ite = s.begin();
	while(ite != s.end()){
		cout << ag[ite->second] << ' ' << ite->first << endl;

		ite++;
	}
	return 0;
}
