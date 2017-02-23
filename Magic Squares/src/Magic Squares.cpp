/*
ID: vlade.m1
PROG: msquare
LANG: C++
 */
#include <fstream>
#include <queue>
#include <map>

std::ifstream fin("msquare.in");
std::ofstream fout("msquare.out");

int main(){
	std::string str = "12348765", goal = "";

	for(int i = 0, inp; i < 8; i++){
		fin >> inp;

		goal += '0' + inp;
	}

	std::swap(goal[4], goal[7]);
	std::swap(goal[5], goal[6]);

	std::map<std::string, int> m;
	std::map<std::string, std::string> best;
	std::queue<std::string> q;
	q.push(str);
	m[str] = 1;
	best[str] = str;

	while(!q.empty()){

		str = q.front();
		for(int i = 0; i < 4; i++){
			std::swap(str[i], str[i + 4]);
		}
		if(m[str] == 0){
			m[str] = m[q.front()] + 1;
			best[str] = q.front();
			q.push(str);
		}

		for(int i = 0; i < 8; i++){
			str[i] = q.front()[(i >= 4) * 4 + (i + 3) % 4];
		}
		if(m[str] == 0){
			m[str] = m[q.front()] + 1;
			best[str] = q.front();
			q.push(str);
		}

		str = q.front();
		str[1] = q.front()[5];
		str[2] = q.front()[1];
		str[5] = q.front()[6];
		str[6] = q.front()[2];
		if(m[str] == 0){
			m[str] = m[q.front()] + 1;
			best[str] = q.front();
			q.push(str);
		}

		q.pop();
	}

	fout << m[goal] - 1 << std::endl;

	std::string res = "";
	str = goal;
	while(best[str] != str){
		std::string copy = best[str];

		if(str[0] == copy[4]){
			res += 'A';
		} else if(str[0] == copy[3]){
			res += 'B';
		} else {
			res += 'C';
		}

		str = copy;
	}


	for(int i = res.length() - 1; i >= 0; i--){
		fout << res[i];
	}

	fout << std::endl;
}
