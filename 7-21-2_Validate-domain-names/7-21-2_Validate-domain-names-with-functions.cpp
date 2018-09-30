#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

// Global variable used for vector sizes
const int MAX_NUMS = 4;

// ***********************************************************************

// GetPeriodPosition - Pass a string and return the position of the period

int GetPeriodPosition(string stringToSearch)
{
  int stringLength = stringToSearch.length();
  int periodCounter = 0;
  int periodPosition = -1;
  int i = 0;

  for (i = 0; i < stringLength; ++i)
  {
    if (stringToSearch[i] == '.')
    {
      ++periodCounter;
      periodPosition = i;
    }
  }

  // If there are zero or two or more periods, indicate an incorrect domain name
  // by setting variable periodPosition to -1
  if (periodCounter != 1)
  {
    periodPosition = -1;
  }
  return periodPosition;
}

// ***********************************************************************

// HasValidSecondLevel  - Returns true if second-level domain is valid, false if not

// A valid second-level domain:

// 1. Is between 1 and 63 characters long
// 2. Contains only upper- and lower-case letters, digits 0-9 and the dash
// 3. Cannot begin or end with a dash

bool HasValidSecondLevel(string secondLevel)
{
  const int MAX_SECONDLEVEL_LENGTH = 63;
  const char DASH = '-';

  bool isValidSecondLevel = true; // Assume valid second-level domain
  int secondLevelLength = secondLevel.length();
  char nextChar = '?';
  int i = 0;

  // Disqualify the second-level domain if it is too short or too long, or
  // if it begins or ends with a dash
  if ((secondLevelLength >= 1) &&
      (secondLevelLength <= MAX_SECONDLEVEL_LENGTH))
  {
    if ((secondLevel[0] == DASH) ||
        (secondLevel[secondLevelLength - 1] == DASH))
    {
      isValidSecondLevel = false;
    }
  }
  else
  {
    isValidSecondLevel = false;
  }

  // Disqualify the second-level domain if any character is not a letter,
  // digit, or a dash
  i = 0;
  while ((i < secondLevelLength) && (isValidSecondLevel))
  {
    nextChar = secondLevel[i];
    if ((!isalnum(nextChar)) && (nextChar != DASH))
    {
      isValidSecondLevel = false;
    }
    ++i;
  }

  return isValidSecondLevel;
}
// ***********************************************************************

// HasValidTld - Returns true if top-level domain is valid, false if not

// A valid top-level domain begins with a period and then contains only
// upper- and lower-case letters, or digits 0-9.

bool HasValidTld(string theTld)
{
  bool isValidTopLevel = true; // Assume valid top-level domain
  int topLevelLength = theTld.length();
  char nextChar = '?';
  int i = 0;

  // Disqualify the top-level domain if it is the empty string or
  // the first character is not a period

  if ((topLevelLength <= 0) || (theTld[0] != '.'))
  {
    isValidTopLevel = false;
  }

  // Disqualify the top-level domain if any character is not a letter or a digit
  i = 1;
  while ((i < topLevelLength) && (isValidTopLevel))
  {
    nextChar = theTld[i];
    if (!isalnum(nextChar))
    {
      isValidTopLevel = false;
    }
    ++i;
  }

  return isValidTopLevel;
}

// ***********************************************************************

// IsSpecialGtld - Takes an array of special gTLD names and a tld candidate.
//                 Returns true if the candidate is a special gTLD, false if not

bool IsSpecialGtld(vector<string> specialGtld, string tld)
{
  bool isSpecial = false;
  int i = 0;

  i = 0;
  while ((i < MAX_NUMS) && (!isSpecial))
  {
    if (specialGtld[i] == tld)
    {
      isSpecial = true;
    }
    else
    {
      ++i;
    }
  }
  return isSpecial;
}

// ***********************************************************************

// getString - Takes a prompt for the user and returns the user's input string

const string GetString(string prompt)
{
  string userInput = "";

  cout << prompt << endl;
  cin >> userInput;

  return userInput;
}

// ***********************************************************************

int main()
{
  const string PROMPT_DOMAIN_NAME = "\nEnter the next domain name (Enter to exit): ";

  // Define the list of valid core gTLDs and restricted gTLDs
  vector<string> validCoreGtld(MAX_NUMS);
  vector<string> validRestrictedGtld(MAX_NUMS);
  string inputName = "";
  string searchName = "";
  string secondLevel = ""; // In aaa.bbb, the aaa part, aka second-level domain
  string theTld = "";      // In aaa.bbb, the bbb part, aka top-level domain
  int periodPosition = 0;
  bool isCoreGtld = false;
  bool isPeriodPositionValid = false;
  bool isRestrictedGtld = false;
  bool isDomainValid = false;

  int i = 0;

  validCoreGtld.at(0) = ".com";
  validCoreGtld.at(1) = ".net";
  validCoreGtld.at(2) = ".org";
  validCoreGtld.at(3) = ".info";
  validRestrictedGtld.at(0) = ".biz";
  validRestrictedGtld.at(1) = ".name";
  validRestrictedGtld.at(2) = ".pro";

  inputName = GetString(PROMPT_DOMAIN_NAME);

  while (inputName.length() > 0)
  {

    searchName = inputName;
    for (i = 0; i < inputName.length(); ++i)
    {
      searchName[i] = tolower(inputName[i]);
    }
    isCoreGtld = false;
    isDomainValid = false;
    periodPosition = GetPeriodPosition(searchName);
    isPeriodPositionValid = (periodPosition >= 1);

    // The domain name is valid if there is exactly one period in the
    // domain name (at location periodPosition) and the domain name does
    // not start or end with a period. Note that a period position of 0 means
    // the first character is a period, rendering the domain name invalid
    if ((periodPosition > 0) && (searchName[searchName.length() - 1] != '.'))
    {
      isPeriodPositionValid = true;
    }
    else
    {
      isPeriodPositionValid = false;
    }
    if (isPeriodPositionValid)
    {

      // Extract the second-level domain and the top-level domain
      secondLevel = searchName.substr(0, periodPosition);
      theTld = searchName.substr(periodPosition);
      isDomainValid = HasValidSecondLevel(secondLevel) && HasValidTld(theTld);

      // If the domain name is valid see if there is a core gTLD or a restricted gTLD
      if (isDomainValid)
      {
        isCoreGtld = IsSpecialGtld(validCoreGtld, theTld);
        if (!isCoreGtld)
        {
          isRestrictedGtld = IsSpecialGtld(validRestrictedGtld, theTld);
        }
      }
    }

    // Display the results
    cout << "\"" << inputName << "\" ";
    if (isDomainValid)
    {
      cout << "is a valid domain name and ";
      if (isCoreGtld)
      {
        cout << "has a core gTLD of \"" << theTld << "\"." << endl;
      }
      else if (isRestrictedGtld)
      {
        cout << "has a restricted gTLD of \"" << theTld << "\"." << endl;
      }
      else
      {
        cout << "has a TLD of \"" << theTld << "\"." << endl;
      }
    }
    else
    {
      cout << "is not a valid domain name." << endl;
    }

    inputName = GetString(PROMPT_DOMAIN_NAME);
  }

  return 0;
}