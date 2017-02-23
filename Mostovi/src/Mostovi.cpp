#include <iostream>
#include <stack>
typedef long long ll;

int main() {
	std::string a, b;
	std::cin >> a >> b;

	int res[a.size() + 1][b.size() + 1];
	std::pair<int, int> match[a.size() + 1][b.size() + 1];
	char letter[a.size() + 1][b.size() + 1];
	res[a.size()][b.size()] = 0;

	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			if(i == 0 or j == 0){
				letter[i][j] = '0';
				match[i][j].first = i;
				match[i][j].second = j;
				res[i][j] = 0;
			} else {
				letter[i][j] = '0';

				if(res[i - 1][j] >= res[i][j - 1]){
					match[i][j].first = i - 1;
					match[i][j].second = j;
					res[i][j] = res[i - 1][j];
				} else {
					match[i][j].first = i;
					match[i][j].second = j - 1;
					res[i][j] = res[i][j - 1];
				}

				if(a[i - 1] == b[j - 1] and res[i - 1][j - 1] + 1 > res[i][j]){
					letter[i][j] = a[i - 1];
					match[i][j].first = i - 1;
					match[i][j].second = j - 1;
					res[i][j] = res[i - 1][j - 1] + 1;
				}
			}
		}
	}

	std::pair<int, int> curr;
	curr.first = a.size();
	curr.second = b.size();

	std::stack<char> s;
	while(curr.first > 0 and curr.second > 0){
		if(letter[curr.first][curr.second] != '0'){
			s.push(letter[curr.first][curr.second]);
		}

		curr = match[curr.first][curr.second];
	}
	while(!s.empty()){
		std::cout << s.top();
		s.pop();
	}
	return 0;
}
