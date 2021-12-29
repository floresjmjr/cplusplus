#include <iostream>
#include <algorithm>
#include "solved.cpp"
using namespace std;

string validateRows()
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
  return "NO Row Mistakes or Incompletes Found";
}

string validateColumns()
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
      container[k] = value;   // Belongs before the count function
    }
    cout << "\n";
  }
  return "NO Column Mistakes or Incompletes Found";
}

void logLine(int arg[])
{
  for (int z = 0; z < 9; z += 1)
  {
    cout << arg[z];
  }
}

string checkCube(int arrStart, int arrEnd, int elStart, int elEnd)
{
  int container[9];
  int indexCounter;
  for (int line = arrStart; line <= arrEnd; line += 1)
  {
    for (int el = elStart; el <= elEnd; el += 1)
    {
      int value = solvedPuzzle[line][el];
      if(value == 0){
        return "Contains empty slot!";
      }
      container[indexCounter] = value;
      int totalCount = count(begin(container), end(container), value);
      if(totalCount > 1){
        return "Contains a duplicate!";
      }
      indexCounter += 1;
    }
  }
  logLine(container);
  return " No empty slots or duplicate numbers";
}

void checkAllCubes()
{
  cout << checkCube(0, 2, 0, 2); //Checks first cube
  cout << "\n";
  cout << checkCube(0, 2, 3, 5); //Checks second cube
  cout << "\n";
  cout << checkCube(0, 2, 6, 8); //Checks third cube
  cout << "\n";
  cout << checkCube(3, 5, 0, 2); //Checks fourth cube
  cout << "\n";
  cout << checkCube(3, 5, 3, 5); //Checks fifth cube
  cout << "\n";
  cout << checkCube(3, 5, 6, 8); //Checks sixth cube
  cout << "\n";
  cout << checkCube(6, 8, 0, 2); //Checks seventh cube
  cout << "\n";
  cout << checkCube(6, 8, 3, 5); //Checks eighth cube
  cout << "\n";
  cout << checkCube(6, 8, 6, 8); //Checks ninth cube
  cout << "\n";
}
