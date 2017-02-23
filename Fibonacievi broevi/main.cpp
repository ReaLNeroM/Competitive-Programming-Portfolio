#include <iostream>
using namespace std;

int main(){

int broj, num = 1, prevnum = 0;
cin>>broj;
while(num <= broj){
cout<<num<<endl;
num += prevnum;
prevnum = num - prevnum;
}

return 0;
}
