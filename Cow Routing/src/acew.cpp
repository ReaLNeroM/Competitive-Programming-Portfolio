#include <fstream>

int transform(std::string copy, int base){
	return (copy[0] - 48) * base * base +
		   (copy[1] - 48) * base +
		   (copy[2] - 48);
}

int main(){
	std::ifstream fin;
	std::ofstream out;
	fin.open("whatbase.in");
	out.open("whatbase.out");
	int cases;
	fin >> cases;

	for(int i = 0; i < cases; i++){
		std::string nx, ny;
		fin >> nx >> ny;

		int ba = 10, bb = 10;

		while(true){
			int cx = transform(nx, ba);
			int cy = transform(ny, bb);
			if(cx < cy){
				ba++;
			} else if(cx != cy){
				bb++;
			} else{
				out << ba << " " << bb << std::endl;
				break;
			}
		}
	}
}
