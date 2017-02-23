#include <iostream>

using namespace std;

int main()
{
    int cekori, stapka = 1, broj = 0;
    cin>>cekori;
    for(int i = 0; i < cekori;i++){
        broj += stapka;
        stapka += 3;
    }
    cout<<broj;
    return 0;
}
