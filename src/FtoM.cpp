#include <iostream>

using namespace std;

int main() {
  double f;
  double m;

  cout << "Enter the length in feet " << endl;
  cin >> f;
  m = f / 3.28;
  cout << f << " feet is " << m << " meteres" << endl;

  return 0;
}