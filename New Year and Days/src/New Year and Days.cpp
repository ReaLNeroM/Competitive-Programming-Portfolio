#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int d;
    cin >> d;
    string str;
    cin >> str >> str;

    if(str[0] == 'm'){
        if(d <= 29){
            cout << 12;
        } else if(d == 30){
            cout << 11;
        } else if(d == 31){
            cout << 7;
        }
    } else {
        if(d == 5 or d == 6){
            cout << 53;
        } else {
            cout << 52;
        }
    }
    return 0;
}
