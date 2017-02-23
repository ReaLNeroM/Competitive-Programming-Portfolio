#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int moves[10000];
	for(int i = 0; i < 10000; i++){
		moves[i] = -1;
	}

	int start;
	cin >> start;

	int end;
	cin >> end;

	int limit;
	cin >> limit;
	for(int j = 0; j < limit; j++){
		std::string s[4];
		for(int k = 0; k < 4; k++){
			cin >> s[k];
		}

		for(int k = 0; k < s[0].size(); k++){
			for(int l = 0; l < s[1].size(); l++){
				for(int m = 0; m < s[2].size(); m++){
					for(int n = 0; n < s[3].size(); n++){
						int res = (((s[0][k] - '0') * 10 + (s[1][l] - '0')) * 10 + (s[2][m] - '0')) * 10 + (s[3][n] - '0');
						moves[res] = -2;
					}
				}
			}
		}
	}

	std::queue<int> q;
	q.push(start);
	moves[start] = 0;
	while(!q.empty()){
		int fr = q.front();
		q.pop();

		int copy;
		for(int one = 1000; one >= 1; one /= 10){
			copy = fr;
			if((fr / one) % 10 < 9){
				copy += one;
			} else {
				copy -= 9 * one;
			}
			if(moves[copy] == -1){
				moves[copy] = moves[fr] + 1;
				q.push(copy);
			}


			copy = fr;
			if((fr / one) % 10 >= 1){
				copy -= one;
			} else {
				copy += 9 * one;
			}
			if(moves[copy] == -1){
				moves[copy] = moves[fr] + 1;
				q.push(copy);
			}
		}
	}

	if(moves[end] == -2){
		moves[end] = -1;
	}
	cout << moves[end];
	return 0;
}
