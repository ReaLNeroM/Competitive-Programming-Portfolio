#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string cokolada;
    cin>>cokolada;

    char bukva;
    cin>>bukva;
    int krsenja = 0;

    for(int i = 0; i < cokolada.length(); i++){
        if(cokolada[i] == bukva){

            if(i != cokolada.length() - 1 && cokolada[i+1] != bukva)
                krsenja++;
            if(i != 0 && cokolada[i-1] != bukva)
                krsenja++;
        }
    }

    cout<<krsenja;

    return 0;
}
