#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    char sign;
    cin>>sign;

    if(sign == '+'){
        cout<<a + b;
    } else if(sign == '-'){
        cout<<a - b;
    } else if(sign == '*'){
        cout<<a * b;
    } else{
        cout<<a / b;
    }

    return 0;
}
