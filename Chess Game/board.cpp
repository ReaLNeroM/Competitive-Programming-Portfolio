#include "board.h"

namespace BoardStructure {
	std::vector<BoardState> boardHistory;
	BoardState board;
	int boardHistorySize;
	Magic::color currMoveColor;
	BoardState initBoard;

	void initTextures(){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < Magic::pieces; j++){
				Magic::pieceTextures[i][j].loadFromFile(Magic::location[i][j]);
				Magic::pieceTextures[i][j].setSmooth(true);
			}
		}
	}

	void init(){
		currMoveColor = Magic::color::white;
		boardHistory.clear();

		initTextures();

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				Magic::color assignedColor = Magic::color::none;
				Magic::type assignedType = Magic::type::blank;
				
				assignedColor = Magic::initialColor[i][j];
				assignedType = Magic::initialType[i][j];

				initBoard[i][j].setPosition(sf::Vector2i(j, i));

				initBoard[i][j] = Piece::Base(assignedColor, assignedType, sf::Vector2i(j, i));
			}
		}

		board = initBoard;
		boardHistory.push_back(initBoard);
		boardHistorySize = 1;
	}

	int getBoardValue(){
		int sum = 0;

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed() and board[i][j].pieceColor != Magic::color::none){
					if(board[i][j].pieceColor == currMoveColor){
						sum += Magic::pieceValue[board[i][j].pieceType];
					} else {
						sum -= Magic::pieceValue[board[i][j].pieceType];
					}
				}
			}
		}

		return sum;
	}

	Piece::Base* find(sf::Vector2i v){
		v = Helper::getIndices(v);
		if(Helper::withinBounds(v) and !board[v.y][v.x].checkDestroyed() and board[v.y][v.x].pieceColor == currMoveColor){
			return &board[v.y][v.x];
		}

		return NULL;
	}

	bool undoMove(){
		if(boardHistory.size() == 1){
			return false;
		}

		boardHistory.pop_back();
		boardHistorySize--;
		board = boardHistory[boardHistory.size() - 1];
		currMoveColor = Helper::getOtherColor(currMoveColor);

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed()){
					board[i][j].reloadTexture();
				}
			}
		}

		return true;
	}

	void recordMove(){
		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed()){
					board[i][j].clearTexture();
				}
			}
		}

		boardHistory.push_back(board);
		boardHistorySize++;
		currMoveColor = Helper::getOtherColor(currMoveColor);

		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed()){
					board[i][j].reloadTexture();
				}
			}
		}
	}

	void drawPieces(sf::RenderWindow &window){
		for(int i = 0; i < Magic::boardSize; i++){
			for(int j = 0; j < Magic::boardSize; j++){
				if(!board[i][j].checkDestroyed()){
					if(currMoveColor == board[i][j].getColor()){
						sf::RectangleShape rectangle(sf::Vector2f(Magic::cellSize, Magic::cellSize));
						rectangle.setPosition(sf::Vector2f(j * Magic::cellSize, i * Magic::cellSize));
						rectangle.setFillColor(sf::Color(0, 0, 0, 0));
						rectangle.setOutlineColor(sf::Color(127, 255, 0, 255));
						rectangle.setOutlineThickness(12.5);
						window.draw(rectangle);
					}

					board[i][j].draw(window);
				}
			}
		}
	}
}
