#include "grader.h"
#include <algorithm>

// If you find it necessary, you may import standard libraries here.

const int table_size = 5500;
const int INF = 1e9;

void helpBessie(int ID){
	if(getCurrentPassIndex() == 0 and getCurrentCarIndex() == 0){
		for(int i = 0; i < table_size; i++){
			set(i, INF);
		}
	}

	int index = getCurrentCarIndex();
	int k = getWindowLength();

	if(getCurrentPassIndex() == 0){
		for(int i = std::max(0, index - k + 1); i <= index and i + k <= getTrainLength(); i++){
			set(i, std::min(get(i), ID));
		}
	} else if(index + k <= getTrainLength()){
		shoutMinimum(get(getCurrentCarIndex()));
	}
}
