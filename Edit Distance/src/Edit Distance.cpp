#include <iostream>
#include <string>

int editdist(std::string a, std::string b){
	int dist[a.length() + 1][b.length() + 1];

	for(int i = 0; i <= a.length(); i++){
		dist[i][0] = i;
	}

	for(int j = 0; j <= b.length(); j++){
		dist[0][j] = j;
	}

	for(int i = 1; i <= a.length(); i++){
		for(int j = 1; j <= b.length(); j++){
			dist[i][j] = std::min(dist[i][j - 1] + 1, dist[i - 1][j] + 1);
			if(a[i - 1] == b[j - 1]){
				dist[i][j] = std::min(dist[i][j], dist[i - 1][j - 1]);
			} else {
				dist[i][j] = std::min(dist[i][j], dist[i - 1][j - 1] + 1);
			}
		}
	}


	return dist[a.length()][b.length()];
}

int main() {
	std::string a, b;
	std::cin >> a >> b;

	std::cout << editdist(a, b);
	return 0;
}





