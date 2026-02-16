#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class SafeArray {
private:
  std::vector<int> data;

public:
  SafeArray(size_t size) : data(size) {}

  void setValue(size_t index, int value) {
    if (index >= data.size()) {
      throw std::out_of_range("Index out of bounds");
    }
    data[index] = value;
  }

  int getValue(size_t index) {
    if (index >= data.size()) {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }
};

int main() {
  SafeArray arr(5);

  try {
    arr.setValue(10, 100);
  } catch (const std::out_of_range &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }
  return 0;
}