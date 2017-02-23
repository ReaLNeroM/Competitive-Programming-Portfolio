#include <iostream>

using namespace std;

int main()
{
    int broj, zbir = 0;
    cin>>broj;

    while(broj >= 1){
        zbir += broj % 10;
        broj /= 10;
    }
    cout<<zbir;
    return 0;
}
