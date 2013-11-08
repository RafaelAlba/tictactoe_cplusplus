#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define PONE_SEL 5
#define PTWO_SEL 10

void default_game_state(int gameState[9])
{
  for (int i = 0; i < 9; i++) {
    gameState[i] = -1;
  }
}

void empty_line()
{
  cout << "   |   |   " << endl;
}

void horizontal_line()
{
  cout << "___|___|___" << endl;
}

void draw_game_board(int gameState[9])
{
  cout << endl;

  empty_line();

  if (gameState[0] == -1)
    cout << " 1 | ";
  else if (gameState[0] == PONE_SEL)
    cout << " O | ";
  else if (gameState[0] == PTWO_SEL)
    cout << " X | ";

  if (gameState[1] == -1)
    cout << "2 | ";
  else if (gameState[1] == PONE_SEL)
    cout << "O | ";
  else if (gameState[1] == PTWO_SEL)
    cout << "X | ";

  if (gameState[2] == -1)
    cout << "3 ";
  else if (gameState[2] == PONE_SEL)
    cout << "O ";
  else if (gameState[2] == PTWO_SEL)
    cout << "X ";

  cout << endl;

  horizontal_line();
  empty_line();

  if (gameState[3] == -1)
    cout << " 4 | ";
  else if (gameState[3] == PONE_SEL)
    cout << " O | ";
  else if (gameState[3] == PTWO_SEL)
    cout << " X | ";

  if (gameState[4] == -1)
    cout << "5 | ";
  else if (gameState[4] == PONE_SEL)
    cout << "O | ";
  else if (gameState[4] == PTWO_SEL)
    cout << "X | ";

  if (gameState[5] == -1)
    cout << "6 ";
  else if (gameState[5] == PONE_SEL)
    cout << "O ";
  else if (gameState[5] == PTWO_SEL)
    cout << "X ";

  cout << endl;

  horizontal_line();
  empty_line();

  if (gameState[6] == -1)
    cout << " 7 | ";
  else if (gameState[6] == PONE_SEL)
    cout << " O | ";
  else if (gameState[6] == PTWO_SEL)
    cout << " X | ";

  if (gameState[7] == -1)
    cout << "8 | ";
  else if (gameState[7] == PONE_SEL)
    cout << "O | ";
  else if (gameState[7] == PTWO_SEL)
    cout << "X | ";

  if (gameState[8] == -1)
    cout << "9 ";
  else if (gameState[8] == PONE_SEL)
    cout << "O ";
  else if (gameState[8] == PTWO_SEL)
    cout << "X ";

  cout << endl;

  empty_line();

  cout << endl;
}

void player_turn(string playerName, int playerMark, int gameState[9])
{
  while (true) {
    // TODO: show only valid options
    cout << playerName << ", please choose your selection (1 - 9): ";
    string choice;
    getline(cin, choice);

    int selection;
    stringstream(choice) >> selection;

    if (selection > 0 && selection < 10) {
      int s = gameState[selection - 1];
      if (s == PTWO_SEL || s == PONE_SEL) {
        cout << endl;
        cout << "That space is already taken, select a different one" << endl << endl;
      } else {
        gameState[selection - 1] = playerMark;
        break;
      }
    } else {
      cout << endl;
      cout << "Please select a valid option (1 - 9)" << endl << endl;
    }
  }
}

bool check_win(int gameState[9])
{
  // horizontally
  int sum = gameState[0] + gameState[1] +  gameState[2];
  if (sum == 15 || sum == 30) {
    return true;
  }

  sum = gameState[3] + gameState[4] + gameState[5];
  if (sum == 15 || sum == 30) {
    return true;
  }

  sum = gameState[6] + gameState[7] + gameState[8];
  if (sum == 15 || sum == 30) {
    return true;
  }

  // vertically
  sum = gameState[0] + gameState[3] + gameState[6];
  if (sum == 15 || sum == 30) {
    return true;
  }

  sum = gameState[1] + gameState[4] + gameState[7];
  if (sum == 15 || sum == 30) {
    return true;
  }

  sum = gameState[2] + gameState[5] + gameState[8];
  if (sum == 15 || sum == 30) {
    return true;
  }

  // diagonally
  sum = gameState[0] + gameState[4] + gameState[8];
  if (sum == 15 || sum == 30) {
    return true;
  }

  sum = gameState[6] + gameState[4] + gameState[2];
  if (sum == 15 || sum == 30) {
    return true;
  }

  return false;
}

void game_loop(string playerOneName, string playerTwoName)
{
  int gameState[9];
  default_game_state(gameState);
  int movesLeft = 9;

  while(true) {
    draw_game_board(gameState);
    player_turn(playerOneName, PONE_SEL, gameState);
    draw_game_board(gameState);
    movesLeft--;

    if (check_win(gameState)) {
      cout << playerOneName << " Wins!!!" << endl << endl;
      break;
    } else if (movesLeft < 1) {
      cout << "It's a tie." << endl << endl;
      break;
    }

    player_turn(playerTwoName, PTWO_SEL, gameState);
    draw_game_board(gameState);
    movesLeft--;

    if (check_win(gameState)) {
      cout << playerTwoName << " Wins!!!" << endl << endl;
      break;
    } else if (movesLeft < 1) {
      cout << "It's a tie." << endl << endl;
      break;
    }

  }
}

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

    game_loop(playerOneName, playerTwoName);

  } else if (2 == selectedOption) {
    cout << "QUITTER!" << endl;

  } else
    cout << "i don't know what you want" << endl;

  return 0;
}
