#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int j = N;
  for (int i = N; i >0; i--) {
    for (int j = 1; j <= i; j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  
  return 0;
}