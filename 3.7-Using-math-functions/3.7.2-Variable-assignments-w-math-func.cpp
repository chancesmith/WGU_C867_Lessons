#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double y = 2.3;
  double z = 3.5;
  z = ceil(y);

  cout << z << endl;

  y = 2.3;
  z = 3.5;
  z = floor(z);

  cout << z << endl;

  z = 4.5;
  z = pow(floor(z), 2.0);

  cout << z << endl;

  z = 15.75;
  z = sqrt(ceil(z));

  cout << z << endl;

  z = fabs(-1.8);

  cout << z << endl;

  return 0;
}