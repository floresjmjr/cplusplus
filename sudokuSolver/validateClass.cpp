#include <iostream>
#include <algorithm>
#include "solved.cpp"
// #include "inputSudoku.cpp"
using namespace std;

class SolutionValidator{
  public:
    bool columns = false;
    bool rows = false;
    bool cubes = false;
  public:
    string checkRows();
    string checkColumns();
    string checkCubes();
};

string SolutionValidator::checkRows()
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9];
    for (int k = 0; k < 9; k += 1)
    {
      int value = solvedPuzzle[i][k];
      cout << value << ", ";
      if (value == 0)
      {
        return "Not Complete";
      }
      int numCount = count(begin(container), end(container), value);
      if (numCount > 1)
      {
        return "Mistake Made";
      }
      container[k] = value;
    }
    cout << "\n";
  }
  rows = true;
  return "Rows contain 1..9 only once";
}

string SolutionValidator::checkColumns()
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9];
    for (int k = 0; k < 9; k += 1)
    {
      int value = solvedPuzzle[k][i];
      cout << value << ", ";
      if (value == 0)
      {
        return "Not Complete";
      }
      int numCount = count(begin(container), end(container), value);
      if (numCount > 1)
      {
        return "Mistake Made";
      }
      container[k] = value;
    }
    cout << "\n";
  }
  columns = true;
  return "Columns contain 1..9 only once";
}

string SolutionValidator::checkCubes(){

  cubes = true;
  return "Cubes contain 1..9 only once";
}