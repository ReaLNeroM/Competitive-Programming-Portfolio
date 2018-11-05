#include "chessAI.h"
#include <ctime>

namespace AI {
	const double INF = 1e9;

	double checkWin(){
		bool check = GameHandler::isKingAttacked(BoardStructure::currMoveColor);
		bool movesLeft = GameHandler::movePossible(BoardStructure::currMoveColor, check);

		if(check and !movesLeft){
			return -INF;
		} else if(!movesLeft){
			return INF/2.0;
		}

		return 0;
	}

	std::pair<sf::Vector2i, sf::Vector2i> bestFirstAction;

	double dfs(int movesLeft, double alpha, double beta){
		double checkValue = checkWin();

		if(checkValue != 0.0){
			return checkValue;
		}

		if(movesLeft == Magic::propagationLimit){
			return BoardStructure::getBoardValue();
		}

		double bestAction = -2.0*INF;

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!BoardStructure::board[i][j].checkDestroyed() and 
					BoardStructure::board[i][j].pieceColor == BoardStructure::currMoveColor){
					sf::Vector2i startPos = sf::Vector2i(j, i);
					for(int k = 0; k < Magic::boardSize; k++){
						for(int l = 0; l < Magic::boardSize; l++){
							sf::Vector2i newPos = sf::Vector2i(l, k);
							if(Helper::withinBounds(newPos) and startPos != newPos and (BoardStructure::board[newPos.y][newPos.x].checkDestroyed() or
																									BoardStructure::board[newPos.y][newPos.x].pieceColor != BoardStructure::currMoveColor)){
								if(GameHandler::validatePieceMove(startPos, newPos, BoardStructure::board[startPos.y][startPos.x], false) and
									 GameHandler::attemptMove(BoardStructure::board[startPos.y][startPos.x], newPos, false)){
									auto response = dfs(movesLeft + 1, alpha, beta);
									response *= -1;
									if(response > bestAction){
										bestAction = response;
										if(movesLeft == 0){
											bestFirstAction = {startPos, newPos};
										}
									}

									BoardStructure::undoMove();

									if(BoardStructure::currMoveColor == Magic::color::white){
										alpha = std::max(alpha, response);
									} else {
										beta = std::min(beta, -response);
									}

									if(alpha >= beta){
										i = j = k = l = Magic::boardSize;
									}
								}
							}
						}
					}
				}
			}
		}

		return bestAction;
	}

	std::map<long long, int> m;
	std::map<long long, int> appearances;

	int explore(){
		bool check = GameHandler::isKingAttacked(BoardStructure::currMoveColor);
		bool movesLeft = GameHandler::movePossible(BoardStructure::currMoveColor, check);

		if(check and !movesLeft){
			if(BoardStructure::currMoveColor == Magic::playerColor){
				m[BoardStructure::hash()] += 100;
				appearances[BoardStructure::hash()] += 1;
				return 100;
			} else {
				m[BoardStructure::hash()] -= 100;
				appearances[BoardStructure::hash()] += 1;
				return -100;
			}
		} else if(!movesLeft){
			if(BoardStructure::currMoveColor == Magic::playerColor){
				m[BoardStructure::hash()] += 1;
				appearances[BoardStructure::hash()] += 1;
				return 1;
			} else {
				m[BoardStructure::hash()] -= 1;
				appearances[BoardStructure::hash()] += 1;
				return -1;
			}
		}

		for(int i = 0; i < Magic::boardSize * Magic::boardSize; i++){
			int a = std::rand() % Magic::boardSize;
			int b = std::rand() % Magic::boardSize;
			sf::Vector2i startPos = sf::Vector2i(b, a);

			if(BoardStructure::board[a][b].getColor() == BoardStructure::currMoveColor and !BoardStructure::board[a][b].checkDestroyed()){
				for(int j = 0; j < Magic::boardSize * Magic::boardSize; j++){
					int c = std::rand() % Magic::boardSize;
					int d = std::rand() % Magic::boardSize;

					sf::Vector2i newPos = sf::Vector2i(d, c);
					if(Helper::withinBounds(newPos) and startPos != newPos and (BoardStructure::board[newPos.y][newPos.x].checkDestroyed() or
																							BoardStructure::board[newPos.y][newPos.x].pieceColor != BoardStructure::currMoveColor)){
						if(GameHandler::validatePieceMove(startPos, newPos, BoardStructure::board[startPos.y][startPos.x], false) and
							 GameHandler::attemptMove(BoardStructure::board[startPos.y][startPos.x], newPos, false)){
							int response = explore();
							response *= -1;

							m[BoardStructure::hash()] += response;
							appearances[BoardStructure::hash()] += 1;

							BoardStructure::undoMove();
							return response;
						}
					}
				}
			}
		}

		return 1.0;
	}

	void monteCarlo(int explorations){
		m.clear();

		std::clock_t begin_time = std::clock();

		for(int i = 0; i < explorations; i++){
			if(i % 10 == 0){
				if((clock() - begin_time) / CLOCKS_PER_SEC > 2.0){
					break;
				}
			}
			explore();
		}

		double bestAction = -2.0*INF;
		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!BoardStructure::board[i][j].checkDestroyed() and 
					BoardStructure::board[i][j].pieceColor == BoardStructure::currMoveColor){
					sf::Vector2i startPos = sf::Vector2i(j, i);
					for(int k = 0; k < Magic::boardSize; k++){
						for(int l = 0; l < Magic::boardSize; l++){
							sf::Vector2i newPos = sf::Vector2i(l, k);
							if(Helper::withinBounds(newPos) and startPos != newPos and (BoardStructure::board[newPos.y][newPos.x].checkDestroyed() or
																									BoardStructure::board[newPos.y][newPos.x].pieceColor != BoardStructure::currMoveColor)){
								if(GameHandler::validatePieceMove(startPos, newPos, BoardStructure::board[startPos.y][startPos.x], false) and
									 GameHandler::attemptMove(BoardStructure::board[startPos.y][startPos.x], newPos, false)){
									if(m[BoardStructure::hash()] / (double) appearances[BoardStructure::hash()] > bestAction){
										bestAction = m[BoardStructure::hash()] / (double) appearances[BoardStructure::hash()];
										bestFirstAction = {startPos, newPos};
									}

									BoardStructure::undoMove();
								}
							}
						}
					}
				}
			}
		}
	}

	std::pair<sf::Vector2i, sf::Vector2i> getBestMove(){
		bestFirstAction = {{-1, -1}, {-1, -1}};
		if(BoardStructure::currMoveColor == Magic::playerColor){
			return bestFirstAction;
		}

		monteCarlo(Magic::branchExplores);
		
		return bestFirstAction;
	}
}
