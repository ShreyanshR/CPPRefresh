#include "vector.h"
#include <iostream>
// #include <string.h>

int main() {

  Vector<std::string> vector;

  vector.PushBack("Paris");
  vector.PushBack("Paris");
  vector.PushBack("Paris");

  return 0;
}

Vector1::Vector1(const Vector1 &a)
    : elem{new double[a.sz]}, sz{a.sz} { // copy constructor
  for (int i = 0; i != sz; i++) {
    elem[i] = a.elem[i]; // copying elments
  }
}

Vector1 &Vector1::operator=(const Vector1 &a) {
  double *p = new double[a.sz];
  for (int i = 0; i != a.sz; ++i) {
    p[i] = a.elem[i]; // copying elments
  }
  delete[] elem; // delted after assignment
  elem = p;
  sz = a.sz;
  return *this;
}