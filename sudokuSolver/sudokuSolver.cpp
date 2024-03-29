#include "inputSudoku.cpp"
// #include "cubeClass.cpp"
#include "solved.cpp"
#include "index.h"
#include <fstream>

//SudokuSolver class
class SudokuSolver
{
public:
  int sudokuState[9][9];
  int *cubePointers[9][9];
  int *columnPointers[9][9];
  int *rowPointers[9][9];
  //int *cubePointers[9][3][3];    //Wouldn't implementing this reduce code in the cubeCombo technique?? You would need top,left,middle,center.... maybe the cubeClass u created?
private:
  void formatCubes();
  void buildCube(int sR, int eR, int sC, int eC, int cube);
  void readSudokuFile();

public:
  SudokuSolver();
  void displayState();
};

void SudokuSolver::readSudokuFile()
{

  ifstream infile("problem.txt");

  int number;
  int counter = 0;
  int nestedCounter = 0;
  while (infile >> number)
  { //While loop necessary as the >> operator reads a string only until it encounters white space character
    sudokuState[counter][nestedCounter] = number;
    if (nestedCounter == 9)
    {
      counter += 1;
      nestedCounter = 0;
      // cout << "\n";
    }
    nestedCounter += 1;
    // cout << number << ", ";
  }
  // cout << "\n";
}

//Solver constructor (would like to pass in a nested array intead of global array)
SudokuSolver::SudokuSolver()
{
  readSudokuFile();
  for (int i = 0; i < 9; i += 1)
  {
    for (int k = 0; k < 9; k += 1)
    {
      // sudokuState[i][k] = inputSudoku[i][k];
      rowPointers[i][k] = &(sudokuState[i][k]);
      columnPointers[k][i] = &(sudokuState[i][k]);
    }
  }
  formatCubes();
}

void SudokuSolver::buildCube(int rowStart, int rowEnd, int cellStart, int cellEnd, int cube)
{
  int indexCounter = 0;
  for (int row = rowStart; row <= rowEnd; row += 1)
  {
    for (int cell = cellStart; cell <= cellEnd; cell += 1)
    {
      cubePointers[cube][indexCounter] = &(sudokuState[row][cell]);
      indexCounter += 1;
    }
  }
}

void SudokuSolver::formatCubes()
{
  buildCube(0, 2, 0, 2, 0); // first cube
  buildCube(0, 2, 3, 5, 1); // second cube
  buildCube(0, 2, 6, 8, 2); // third cube
  buildCube(3, 5, 0, 2, 3); // fourth cube
  buildCube(3, 5, 3, 5, 4); // fifth cube
  buildCube(3, 5, 6, 8, 5); // sixth cube
  buildCube(6, 8, 0, 2, 6); // seventh cube
  buildCube(6, 8, 3, 5, 7); // eighth cube
  buildCube(6, 8, 6, 8, 8); // ninth cube
}

void SudokuSolver::displayState()
{
  cout << "++=================================++"
       << "\n";
  for (int i = 0; i < 9; i += 1)
  {
    cout << "||";
    for (int k = 0; k < 9; k += 1)
    {
      cout << " " << sudokuState[i][k] << " ";
      if (((k - 2) % 3) == 0)
      {
        cout << "|| ";
      }
    }
    cout << "\n";
    if (((i - 2) % 3) == 0)
    {
      if (i < 8) //To avoid a third line
      {
        cout << "||=================================||"
             << "\n";
      }
    }
  }
  cout << "++=================================++"
       << "\n";
}