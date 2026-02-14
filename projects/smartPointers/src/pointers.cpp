#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

int *createArray(int size) { return new int[size]; }

std::unique_ptr<int[]> createArray2(int size) {
  return std::make_unique<int[]>(size);
}

class Shallow {
public:
  int *data;

  Shallow(int value) { data = new int(value); }
  Shallow(const Shallow &obj) {
    data = obj.data; // just copying the pointer
  }
  ~Shallow() {
    delete data; // when copy constructor is called, both points to teh same
                 // memory
    // So where after 1 will be deleted other is pointing to an Dangling pointer
    //& can lead to undefiend behavior
    // by defaulf it we don't have our copy constructor we are doing shallow
    // copy,where it copying is pointer
  }
};

class Deep {
public:
  int *data;

  Deep(int value) { data = new int(value); }

  Deep(const Deep &obj) { data = new int(*obj.data); }
  ~Deep() {
    delete data; // safe to call delete
  }
};

class Buffer {
private:
  int *data;
  size_t size;

public:
  Buffer(size_t sz) : size(sz) {
    data = new int[size];
    std::cout << "Buffer of size : " << size << std::endl;
  }

  Buffer(const Buffer &other) : size(other.size) {
    data = new int[size]; // init size on heap
    for (size_t i = 0; i < size; i++) {
      data[i] = other.data[i]; // copy each integer
    }
  }

  // Move Construcotr
  Buffer(Buffer &&other) noexcept
      : data(other.data),
        size(other.size) { // stealing resources in the construcor
    // move B1(other) to B2, & empty B1
    // data = other.data;
    // size = other.size;

    // leve other in valid & empty state
    other.data = nullptr; //
    other.size = 0;
    std::cout << "Buffer moved" << std::endl;
  }

  ~Buffer() { delete[] data; }

  void displaySize() const { std::cout << "Size " << size << std::endl; }
};

class Car {
public:
  std::string model;

  Car &setModel(const std::string &m) {
    this->model = m;
    return *this;
  }

  void printModel() { std::cout << "Car model: " << this->model << std::endl; }
};

int main() {

  Car myCar;
  myCar.setModel("Tesla").printModel();
  int size = 5;
  int *myArray = createArray(size);

  for (int i = 0; i < size; i++) {
    myArray[i] = i * 10;
    std::cout << myArray[i] << std::endl;
  }
  auto myArray1 = createArray2(size);
  for (int i = 0; i < size; i++) {
    myArray1[i] = i * 20;
    std::cout << myArray1[i] << std::endl;
  }

  delete[] myArray;

  Buffer buff1(5);
  buff1.displaySize();

  Buffer buff2(std::move(buff1));
  buff1.displaySize();
  buff2.displaySize();

  std::vector<Buffer> buffers;

  std::cout << "Buffer Capacity: " << buffers.capacity() << std::endl;

  for (int i = 0; i < 5; i++) {
    buffers.push_back(Buffer(100));
    std::cout << "Buffer capacity: " << buffers.capacity()
              << " after pushing: " << i << std::endl;
  }
  return 0;
}