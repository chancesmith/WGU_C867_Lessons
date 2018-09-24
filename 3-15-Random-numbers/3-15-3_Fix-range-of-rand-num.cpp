#include <iostream>
#include <cstdlib>   // Enables use of rand()
#include <ctime>     // Enables use of time()
using namespace std;

int main() {
   int seedVal = 0;

   seedVal = 4;
   srand(seedVal);

   cout << (rand() % (149 - 100 + 1)) + 100 << endl;
   cout << (rand() % (149 - 100 + 1)) + 100 << endl;

   return 0;
}