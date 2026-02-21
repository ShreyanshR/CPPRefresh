#include <iostream>
#include <utility>

void process(int &x) { std::cout << "By lvalue " << x << std::endl; }
void process(int &&x) { std::cout << "By Rvalue " << x << std::endl; }

template <typename T> void forwardToProcess(T &&arg) {
  // process(std::forward<T>(arg)); // perfect forwarding
  process(arg);
}

template <int N> struct Fibonacci {
  // constexpr int value =
  static_assert(N >= 0, "Fibonacci not defined for negative integers");
  static constexpr int value =
      Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <> struct Fibonacci<0> {
  // constexpr int value = 0;
  static constexpr int value = 0;
};

template <> struct Fibonacci<1> {
  static constexpr int value = 1;
};

int main() {
  int a = 10;

  forwardToProcess(a);
  forwardToProcess(15);

  constexpr int fib10 = Fibonacci<10>::value;

  std::cout << "Fib: " << fib10 << std::endl;
}
