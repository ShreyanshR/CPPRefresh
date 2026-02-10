#include <iostream>

int main() {
  int *p, num;
  p = &num;

  *p = 100;

  std::cout << num << std::endl;
  (*p)++;
  std::cout << num << std::endl;
  (*p)--;
  std::cout << num << std::endl;

  return 0;
}