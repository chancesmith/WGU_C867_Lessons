
#include <iostream>
#include <cmath>
using namespace std;

class RightTriangle
{
public:
  void SetSide1(double side1Val);
  void SetSide2(double side2Val);
  double GetHypotenuse() const;

private:
  double side1;
  double side2;
};

void RightTriangle::SetSide1(double side1Val)
{
  side1 = side1Val;

  return;
}

void RightTriangle::SetSide2(double side2Val)
{
  side2 = side2Val;
  return;
}

double RightTriangle::GetHypotenuse() const
{
  return sqrt((side1 * side1) + (side2 * side2));
}

int main()
{
  RightTriangle triangleA;

  triangleA.SetSide1(3.0);
  triangleA.SetSide2(4.0);

  cout << "Hypotenuse: " << triangleA.GetHypotenuse() << endl;
  // Should output 5 for the above side values

  return 0;
}
