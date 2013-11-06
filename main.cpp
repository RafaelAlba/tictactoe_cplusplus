#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  cout << "1. New Game" << endl;
  cout << "2. Quit" << endl;
  cout << endl;

  cout << "Please select an option (1 or 2): ";

  string choice;
  getline(cin, choice);

  int selectedOption;
  stringstream(choice) >> selectedOption;

  if (1 == selectedOption)
    cout << "You chose to start a new game!" << endl;
  else if (2 == selectedOption)
    cout << "QUITTER!" << endl;
  else
    cout << "i don't know what you want" << endl;

  return 0;
}
