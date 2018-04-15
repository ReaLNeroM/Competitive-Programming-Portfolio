#include <iostream>
#include "src.cpp"

int main(){
  Squares x;
  std::cout << x.findMax({1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4}, 
  						 {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4});
}