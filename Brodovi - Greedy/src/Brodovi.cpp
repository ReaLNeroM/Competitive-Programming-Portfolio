#include <iostream>
#include <algorithm>

struct boat{
    int point, length;

    bool operator<(const boat &x) const{
        return (point < x.point);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int boats;
    std::cin >> boats;

    boat b[boats];
    for(int i = 0; i < boats; i++){
        std::cin >> b[i].length >> b[i].point;
    }

    std::sort(b, b + boats);

    int res = 1;
    boat last = b[0];

    for(int i = 1; i < boats; i++){
    	if(b[i].point >= last.point){
    		res++;
    		if(b[i].point - b[i].length < last.point){
    			last.length = b[i].length;
				last.point += last.length;
    		} else {
				last = b[i];
    		}
    	} else if (last.length > b[i].length) {
    		last.point = std::max(last.point + b[i].length - last.length, b[i].point);
    		last.length = b[i].length;
    	}
    }

    std::cout << res;
    return 0;
}
