#include <iostream>
#include <vector>
#include <queue>

class BichromeBoard{
	struct coord{
		int x, y;
	} copy;

	std::queue<coord> q;

	bool BFS(std::vector<std::string> &board){
		while(!q.empty()){
			if(q.front().x != 0){
				if(board[q.front().x - 1][q.front().y] == '?'){
					board[q.front().x - 1][q.front().y] = (board[q.front().x][q.front().y] == 'B') ? 'W' : 'B';
					copy.x = q.front().x - 1, copy.y = q.front().y;
					q.push(copy);
				} else if(board[q.front().x - 1][q.front().y] == board[q.front().x][q.front().y]){
					return false;
				}
			}
			if(q.front().x != board[0].size()){
				if(board[q.front().x + 1][q.front().y] == '?'){
					board[q.front().x + 1][q.front().y] = (board[q.front().x][q.front().y] == 'B') ? 'W' : 'B';
					copy.x = q.front().x + 1, copy.y = q.front().y;
					q.push(copy);
				} else if(board[q.front().x + 1][q.front().y] == board[q.front().x][q.front().y]){
					return false;
				}
			}
			if(q.front().y != 0){
				if(board[q.front().x][q.front().y - 1] == '?'){
					board[q.front().x][q.front().y - 1] = (board[q.front().x][q.front().y] == 'B') ? 'W' : 'B';
					copy.x = q.front().x, copy.y = q.front().y - 1;
					q.push(copy);
				} else if(board[q.front().x][q.front().y - 1] == board[q.front().x][q.front().y]){
					return false;
				}
			}
			if(q.front().y != board.size()){
				if(board[q.front().x][q.front().y + 1] == '?'){
					board[q.front().x][q.front().y + 1] = (board[q.front().x][q.front().y] == 'B') ? 'W' : 'B';
					copy.x = q.front().x, copy.y = q.front().y + 1;
					q.push(copy);
				} else if(board[q.front().x][q.front().y + 1] == board[q.front().x][q.front().y]){
					return false;
				}
			}
			q.pop();
		}

		return true;
	}

public:
	std::string ableToDraw(std::vector<std::string> board){
		bool foundone = false;
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[i].size(); j++){
				if(board[i][j] != '?'){
					copy.x = i, copy.y = j;
					foundone = true;
					q.push(copy);
					if(!BFS(board)){
						return "Impossible";
					}
				}
			}
		}

		if(!foundone){
			board[0][0] = 'B';
			copy.x = 0, copy.y = 0;
			q.push(copy);
			if(!BFS(board)){
				return "Impossible";
			}
		}

		return "Possible";
	}
};
int main() {
	BichromeBoard a;
	std::cout << a.ableToDraw();
	return 0;
}
