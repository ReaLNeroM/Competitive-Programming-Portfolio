#include <iostream>
using namespace std;

int main() {
    int golemina;
    cin >> golemina;
    int linii[golemina][golemina], follx = -1, c, zbir = 0;
    for (int i = 0; i < golemina; i++) {
        for (int j = 0; j < golemina; j++) {
            cin >> linii[i][j];
            if (linii[i][j] == -1) {
                follx = i;
                linii[i][j] = 0;
            }
        }
        if (follx != -1 && i != 0) {
            if (follx == i-1) {
                c = i;
            } else {
                c = i-1;
            }
            for (int k = 0; k < golemina; k++) {
                zbir += linii[c][k];
                zbir -= linii[follx][k];
            }
            follx = -1;
        }
    }

    cout<<zbir;
    return 0;
}
