#include <iostream>

int main() {
  double moon_gravity, earth_gravity;

  for (earth_gravity = 1; earth_gravity < 100; earth_gravity++) {
    moon_gravity = earth_gravity * .17;
    int counter = 0;
    std::cout << "Earth Weight " << earth_gravity << " moon weight "
              << moon_gravity << std::endl;
    counter++;

    if (counter == 25)
      std::cout << "\n";
    counter = 0;
  }

  return 0;
}