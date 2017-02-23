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

    int smallest = 0;
    boat b[boats];
    for(int i = 0; i < boats; i++){
        std::cin >> b[i].length >> b[i].point;
        if(b[i].point < b[i].length){
            smallest = std::max(smallest, b[i].length - b[i].point);
        }
    }

    for(int i = 0; i < boats; i++){
        b[i].point += smallest;
    }

    std::sort(b, b + boats);

    int best[b[boats - 1].point + 1];
    for(int i = 0; i <= b[boats - 1].point; i++){
        best[i] = 0;
    }

    int check, end, curr;
    for(int j = boats - 1; j >= 0; j--){
        check = best[b[j].point] + 1;
        for(int i = b[j].point - b[j].length; i >= 0; i--){
        	if(check > best[i]){
        		best[i] = check;
        	}
        }

        end = std::min(b[j].point, b[boats - 1].point - b[j].length), curr = b[j].point + 1;
        int i;
        for(i = b[j].point - b[j].length + 1; i <= end; i++, curr++){
        	if(best[curr] >= best[i]){
        		best[i] = best[curr] + 1;
        	}
        }
        for(; i <= b[j].point; i++){
        	if(1 > best[i]){
        		best[i] = 1;
        	}
        }
    }

    std::cout << best[0];
    return 0;
}
