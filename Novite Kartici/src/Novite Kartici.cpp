#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

//topological sortingo e greska
//gleda go prvo NAJVISOKIO element, a posle leksikografski najmalio
//mora n^2 algoritam za da e tocen

struct card {
	string full;
	string num;
	int incoming;
};

bool cmp(card &a, card &b){
	bool good = false;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(a.full[i] == b.full[j]){
				good = true;
				break;
			}
		}
	}

	return (good and a.num < b.num);
}

bool secondcmp(card const &x, card const &y) {
	return x.full < y.full;
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	card c[n];
	for(int i = 0; i < n; i++){
		cin >> c[i].full;
		c[i].num = "";
		c[i].incoming = 0;
		for(int j = 4; j <= 6; j++){
			c[i].num += c[i].full[j];
		}
	}
	sort(c, c + n, secondcmp);

	vector<int> watch[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(cmp(c[i], c[j]) == true){
				c[j].incoming++;
				watch[i].push_back(j);
			}
		}
	}

	queue<int> q;
	for(int i = 0; i < n; i++){
		if(c[i].incoming == 0){
			q.push(i);
		}
	}

	for(int i = 0; i < n; i++){
		int next = q.front();
		q.pop();

		for(int j = 0; j < watch[next].size(); j++){
			c[watch[next][j]].incoming--;
			if(c[watch[next][j]].incoming == 0){
				q.push(watch[next][j]);
			}
		}
		c[next].incoming = -1;

		cout << c[next].full << endl;
	}
	return 0;
}
