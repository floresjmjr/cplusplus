#include <iostream>
#include "puzzle.cpp"
using namespace std;

bool containsAllNums(int arg[])
{
  //
  return false;
}

void validateCube(int line)
{
  for (int i = 0; i < 3; i += 1)
  {
    for (int k = 0; k < 3; k += 1)
    {
      cout << puzzle[line][i][k] << ", ";
    }
  }
}

//Checks each Cube
void validateCubes()
{
  cout << "Validate Cubes"
       << "\n";
  for (int i = 0; i < 9; i += 1)
  {
    validateCube(i);
    cout << "\n";
  }
}

void topRow(int row)
{
  for (int i = 0; i < 3; i += 1)
  {
    for (int k = 0; k < 3; k += 1)
    {
      cout << puzzle[i][row][k] << ", ";
    }
  }
}

void middleRow(int row)
{
  for (int i = 3; i < 6; i += 1)
  {
    for (int k = 0; k < 3; k += 1)
    {
      cout << puzzle[i][row][k] << ", ";
    }
  }
}

void bottomRow(int row)
{
  for (int i = 6; i < 9; i += 1)
  {
    for (int k = 0; k < 3; k += 1)
    {
      cout << puzzle[i][row][k] << ", ";
    }
  }
}

void validateRows()
{
  cout << "Validate Rows"
       << "\n";
  //Top rows
  for (int row = 0; row < 3; row += 1)
  {
    topRow(row);
    cout << "\n";
  }

  //Middle rows
  for (int row = 0; row < 3; row += 1)
  {
    middleRow(row);
    cout << "\n";
  }

  //Middle rows
  for (int row = 0; row < 3; row += 1)
  {
    bottomRow(row);
    cout << "\n";
  }


}

// int validatePuzzle()
// {
//   bool horizontal = horizontalCheck();
//   bool vertical = verticalCheck();
// }
