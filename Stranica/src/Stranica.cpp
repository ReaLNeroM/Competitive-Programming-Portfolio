#include <iostream>
#include <queue>
#include <cmath>

int bfs(int solut, std::string usable) {
    std::queue<int> q;
    q.push(0);
    int used[200000];

    for(int i = 0; i < 200000; i++){
    	if(i < 100){
    		used[i] = i;
    	} else{
    	used[i] = i - 100;
    	}
    }

    do {
    	int atcurr;
        for (int i = 0; i < usable.length(); i++) {
        	atcurr = q.front() * 10 + usable[i] - 48;
        	if (atcurr < 200000 and used[atcurr] >= used[q.front()] + 1) {
                used[atcurr] = used[q.front()] + 1;
                q.push(atcurr);
            }
            used[solut] = std::min(used[solut], used[q.back()] + (int) std::abs(q.back() - solut));
		}
		q.pop();
	} while (!q.empty());

	return used[solut];
}

int main() {
    int broj, skrseni;
    std::cin >> broj >> skrseni;

    std::string usable = "0123456789";

    for (int i = 0; i < skrseni; i++) {
        char copy;
        std::cin >> copy;
        for (int j = 0; j < usable.length(); j++) {
            if (copy == usable[j]) {
                usable.erase(usable.begin() + j);
                break;
            }
        }
    }
    std::cout << bfs(broj, usable);
}
