#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 20;
int offset[maxn];
int interval[maxn];
int speed[maxn];

void exit(){
    std::cout << "squish\n";
    std::exit(0);
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int h, w;
    std::cin >> h >> w;

    for(int i = 0; i < h; i++){
        std::cin >> offset[i] >> interval[i] >> speed[i];
    	offset[i]++;
    }

    int start;
    std::cin >> start;

    std::string moves;
    std::cin >> moves;

    int y = h;
    int x = start;

    for(int i = 0; i < moves.size(); i++){
        bool good = true;
        if(moves[i] == 'L'){
            x--;
        } else if(moves[i] == 'R'){
            x++;
            x = std::min(x, w - 1);
        } else if(moves[i] == 'U'){
            y--;
        } else if(moves[i] == 'D'){
            y++;
            if(y == h){
            	exit();
            }
        }
		if(x < 0 or x >= w or y > h){
			exit();
		}

        if(y >= 0 and y < h){
            if(interval[y] <= speed[y]){
                good = false;
            }
            if((x + interval[y] - offset[y]) % interval[y] < speed[y]){
                good = false;
            }
        }

        if(!good){
            break;
        }

        for(int j = 0; j < h; j++){
            offset[j] = (offset[j] + speed[j]) % interval[j];
        }
    }

    if(y < 0){
        std::cout << "safe\n";
        return 0;
    }

    exit();
}
