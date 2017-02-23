#include <iostream>

using namespace std;

int main()
{
    int inp, broj, zbir = 0;
    cin>>inp;
    for(int i = 0; i < inp;i++){
        cin>>broj;
        zbir += broj;
    }
    cout<<zbir;
    return 0;
}
