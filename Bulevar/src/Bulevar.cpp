#include <iostream>
#include <set>

int main(){
    int parceli, space, izgradeni;
    std::cin >> parceli >> space >> izgradeni;

   	bool buildable[parceli];

   	for(int i = 0; i < parceli; i++){
   		buildable[i] = true;
   	}

    for(int i = 0; i < izgradeni; i++){
    	int transfer;
    	std::cin >> transfer;
    	buildable[transfer - 1] = false;
    }

    int result = 0;
    for(int i = 0; i < parceli; i++){
    	bool able = true;
    	for(int j = std::max(i % 2, i - space * 2); j <= std::min(i + space * 2, parceli - 1); j += 2){
    		if(!buildable[j]){
    			able = false;
    			break;
    		}
    	}

    	if(able){
    		buildable[i] = false;
    		result++;
    	}
    }

    std::cout << result;
    return 0;
}
