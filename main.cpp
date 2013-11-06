#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  cout << "1. New Game" << endl;
  cout << "2. Quit" << endl << endl;
  cout << endl;

  cout << "Please select an option (1 or 2): ";

  string choice;
  getline(cin, choice);

  int selectedOption;
  stringstream(choice) >> selectedOption;

  if (1 == selectedOption) {
    string playerOneName;
    string playerTwoName;

    cout << "Starting New Game!" << endl << endl;

    cout << "Please enter a name for player one: ";
    getline(cin, playerOneName);
    cout << "Name for first player: " << playerOneName << endl;

    cout << "Please enter a name for player two: ";
    getline(cin, playerTwoName);
    cout << "Name for second player: " << playerTwoName << endl;

  } else if (2 == selectedOption) {
    cout << "QUITTER!" << endl;

  } else
    cout << "i don't know what you want" << endl;

  return 0;
}
