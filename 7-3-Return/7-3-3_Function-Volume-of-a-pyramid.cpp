#include <iostream>
using namespace std;

double PyramidVolume(double baseLength, double baseWidth, double height)
{
  // watch out for integer division (1/3)
  return ((baseLength * baseWidth) * height * (1.0 / 3.0));
}

int main()
{
  cout << "Volume for 1.0, 1.0, 1.0 is: " << PyramidVolume(1.0, 1.0, 1.0) << endl;
  return 0;
}