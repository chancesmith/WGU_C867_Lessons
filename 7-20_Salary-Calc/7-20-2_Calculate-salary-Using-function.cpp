#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to prompt for and input an integer
int PromptForInteger(const string userPrompt) {
   int inputValue = 0;

   cout << userPrompt << ": " << endl;
   cin >> inputValue;

   return inputValue;
}

// *************************************************************************

// Function to get a value from one table based on a range in the other table
double GetCorrespondingTableValue(int search, vector<int> baseTable, vector<double> valueTable) {
   int baseTableLength = baseTable.size();
   double value = 0.0;
   int i = 0;
   bool keepLooking = true;

   while ((i < baseTableLength) && keepLooking) {
      if (search <= baseTable.at(i)) {
         value = valueTable.at(i);
         keepLooking = false;
      }
      else {
         ++i;
      }
   }

   return value;
}

// **********************************************************************

int main() {
   const string USER_PROMPT = "\nEnter annual salary (negative to exit)";
   int annualSalary = 0;
   double taxRate = 0.0;
   int taxToPay = 0;
   int i = 0;
   vector<int> salaryBase(5);
   vector<double> taxBase(5);

   // The first entries in the two tables are 0 to catch annualSalary < 0
   salaryBase.at(0) = 0;
   salaryBase.at(1) = 20000;
   salaryBase.at(2) = 50000;
   salaryBase.at(3) = 100000;
   salaryBase.at(4) = 99999999;

   taxBase.at(0) = 0.0;
   taxBase.at(1) = 0.10;
   taxBase.at(2) = 0.20;
   taxBase.at(3) = 0.30;
   taxBase.at(4) = 0.40;

   annualSalary = PromptForInteger(USER_PROMPT);

   while(annualSalary >= 0) {
      taxRate = GetCorrespondingTableValue(annualSalary, salaryBase, taxBase);

      taxToPay = static_cast<int>(annualSalary * taxRate);    // Truncate tax to an integer amount
      cout << "Annual salary: " << annualSalary <<
              "\nTax rate: " << taxRate <<
              "\nTax to pay: " << taxToPay << endl;

      // Get the next annual salary
      annualSalary = PromptForInteger(USER_PROMPT);
   }

   return 0;
}
