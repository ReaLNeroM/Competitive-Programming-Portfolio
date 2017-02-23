#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cokolado[200];
    for(int i = 0; i < 5; i++){
        cin>>cokolado[i];
    }

    char bukva;
    cin>>bukva;
    bool ended = false;
    int krsenja = 0;
    for(int i = 0; i < (sizeof(cokolado)/sizeof(*cokolado)); i++){
        if(cokolado[i] == bukva){

            if(cokolado[i++] == bukva){
                krsenja++;
                cokolado[i++] == bukva - 1;
            }
           // if(cokolado[])
            if(cokolado[i--] == bukva){
                krsenja++;
                cokolado[i--] == bukva - 1;
            }
        }
    }

    cout<<krsenja;

    return 0;
}
