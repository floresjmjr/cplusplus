#include <iostream>
#include <algorithm>
// #include "inputSudoku.cpp"
using namespace std;

class SolutionValidator
{
public:
  bool columns = false;
  bool rows = false;
  bool cubes = false;

public:
  //Can refactor these functions and create a "parent" function which they all use
  string checkRows(int nestedArr[9][9]);
  string checkColumns(int nestedArr[9][9]);
  string checkCubes(int *nestedArr[9][9]);
};

string SolutionValidator::checkColumns(int nestedArr[9][9])
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //The assignement of "0" is necessary to "reset" the array
    for (int k = 0; k < 9; k += 1)
    {
      int value = nestedArr[k][i];
      cout << value << ", ";
      if (value == 0)
      {
        return "Not Complete";
      }
      container[k] = value;
      int numCount = count(begin(container), end(container), value);
      if (numCount > 1)
      {
        return "Mistake Made";
      }
    }
    cout << "\n";
  }
  rows = true;
  return "Columns contain 1..9 only once";
}

string SolutionValidator::checkRows(int nestedArr[9][9])
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int k = 0; k < 9; k += 1)
    {
      int value = nestedArr[i][k];
      cout << value << ", ";
      if (value == 0)
      {
        return "Not Complete";
      }
      container[k] = value;
      int numCount = count(begin(container), end(container), value);
      if (numCount > 1)
      {
        return "Mistake Made";
      }
    }
    cout << "\n";
  }
  columns = true;
  return "Rows contain 1..9 only once";
}

string SolutionValidator::checkCubes(int *arr[9][9])
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int k = 0; k < 9; k += 1)
    {
      int value = *(arr[i][k]);
      cout << value << ", ";
      if (value == 0)
      {
        return "Not Complete";
      }
      container[k] = *(arr[i][k]);
      int totalCount = count(begin(container), end(container), value);
      if (totalCount > 1)
      {
        return "Mistake made";
      }
    }
    cout << "\n";
  }
  cubes = true;
  return "Cubes contain 1..9 only once";
}