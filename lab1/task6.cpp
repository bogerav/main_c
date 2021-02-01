#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  for (int i = N; i >0; i = i-2) {
    for (int k = (N-i) / 2; k > 0; k--) {
        std::cout << ' ';
      }
    for (int j = 1; j <= i; j++) {
      
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  
  return 0;
}