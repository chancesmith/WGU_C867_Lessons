#include <iostream>
using namespace std;

void PrintShampooInstructions(int numCycles)
{
  if (numCycles < 1)
  {
    cout << "Too few." << endl;
  }
  else if (numCycles > 4)
  {
    cout << "Too many." << endl;
  }
  else
  {
    for (int i = 0; i < numCycles; i++)
    {
      cout << i + 1 << ": Lather and rinse." << endl;
    }
    cout << "Done." << endl;
  }
  return;
}

int main()
{
  PrintShampooInstructions(2);

  return 0;
}