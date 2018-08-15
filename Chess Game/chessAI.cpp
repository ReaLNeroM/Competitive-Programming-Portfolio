#include "chessAI.h"

namespace AI {
	const int INF = 10000;

	int checkWin(){
		bool check = GameHandler::isKingAttacked(BoardStructure::currMoveColor);
		bool movesLeft = GameHandler::movePossible(BoardStructure::currMoveColor, check);

		if(check and !movesLeft){
			return -INF;
		} else if(!movesLeft){
			return -1;
		}

		return 0;
	}

	std::pair<int, std::pair<sf::Vector2i, sf::Vector2i>> dfs(int movesLeft){
		int checkValue = checkWin();

		if(checkValue == -INF or checkValue == -1){
			return {checkValue, {sf::Vector2i(0, 0), sf::Vector2i(0, 0)}};
		}

		if(movesLeft == 0){
			return {BoardStructure::getBoardValue(), {sf::Vector2i(0, 0), sf::Vector2i(0, 0)}};
		}

		std::pair<int, std::pair<sf::Vector2i, sf::Vector2i>> bestAction = {-INF, {sf::Vector2i(0, 0), sf::Vector2i(0, 0)}};

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
									auto response = dfs(movesLeft - 1);
									response.first *= -1;
									if(response.first > bestAction.first){
										bestAction = response;
										bestAction.second = {startPos, newPos};
									}

									BoardStructure::undoMove();
								}
							}
						}
					}
				}
			}
		}

		return bestAction;
	} 

	std::pair<sf::Vector2i, sf::Vector2i> getBestMove(){
		auto x = dfs(4);
		return x.second;
	}
}
