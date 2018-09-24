#include <iostream>
using namespace std;

int main()
{
  int hourlyWage = 20;
  int workHoursPerWeek = 35;
  // FIXME: Declare and initialize variable workWeeksPerYear, then replace the 50's below
  int workWeeksPerYear = 52;
  int annualSalary = 0;
  int monthlySalary = 0;

  annualSalary = hourlyWage * workHoursPerWeek * workWeeksPerYear;
  cout << "Annual salary is: ";
  cout << annualSalary << endl;

  monthlySalary = (hourlyWage * workHoursPerWeek * workWeeksPerYear) / 12;
  cout << "Monthly salary is: ";
  cout << monthlySalary << endl;

  return 0;
}