#include <iostream>
#include <vector>

class Vectors {
private:
  double x, y;

public:
  Vectors(double x, double y) : x(x), y(y) {}

  Vectors operator+(const Vectors &v1) {
    return Vectors(this->x + v1.x, this->y + v1.y);
  }

  Vectors operator-(const Vectors &v2) {
    return Vectors(this->x - v2.x, this->y - v2.y);
  }

  void display() { std::cout << "x: " << x << " y: " << y << std::endl; }
};

class Vector {
private:
  double x, y;

public:
  Vector(double x, double y) : x(x), y(y) {}

  friend Vector operator+(const Vector &v1, const Vector &v2);
};

Vector operator+(const Vector &v1, const Vector &v2) {
  return Vector(v1.x + v2.x, v1.y + v2.y);
}

int main() {
  Vectors v1(2.0, 3.0);
  Vectors v2(5.0, 6.0);

  Vectors v3 = v1 + v2;

  v3.display();

  return 0;
}