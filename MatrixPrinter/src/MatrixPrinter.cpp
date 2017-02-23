#include <string>

typedef long long ll;

class MatrixPrinter {
public:
	std::string printMatrix(int rows, int columns, std::string matrix) {
		std::string mat[rows][columns];

		int pos = 0;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				while(matrix[pos] != ' ' and pos < matrix.length()){
 					mat[i][j] += matrix[pos];
					pos++;
				}
				pos++;
			}
		}

		std::string res = "";
		int posx, posy;
		for(int i = 0; i < columns; i++){
			posx = i, posy = 0;
			while(posx >= 0 and posy < rows){
				res += mat[posy][posx];
				res += ' ';
				posx--, posy++;
			}
		}
		for(int i = 1; i < rows; i++){
			posx = columns - 1, posy = i;
			while(posx >= 0 and posy < rows){
				res += mat[posy][posx];
				res += ' ';
				posx--, posy++;
			}
		}

		res.erase(res.end() - 1);
		return res;
	}
};
