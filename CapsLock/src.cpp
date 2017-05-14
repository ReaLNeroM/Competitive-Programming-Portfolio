#include <string>
#include <vector>
using namespace std;

class CapsLock{
public:
	int fewerPushes(string message){
		int state = 0;
		int res = 0;
		
		for(int i = 0; i < message.size(); i++){
			if('a' <= message[i] and message[i] <= 'z'){
				if(state == 1){
					state = 0;
					res++;
				}
			} else if('A' <= message[i] and message[i] <= 'Z'){
				if(state == 0){
					state = 1;
					res++;
				}
			}
		}

		return res;
	}
};
