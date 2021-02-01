#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int i = 1; i <= N; i++) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }
  
  return 0;
}