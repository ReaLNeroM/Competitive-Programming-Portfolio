#include <iostream>
#include "src.cpp"

int main(){
  ClosedSet x;
  std::cout << x.closedSet({1,2,3,4,5,8,9}, 7, 4, 10);
}